const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

let li = 0; // lineInput

const [R, C] = input[li++].split(" ").map((e) => Number(e));
const arr = Array.from({ length: R }, () =>
  input[li++].split(" ").map((e) => Number(e))
);
const ans = Array.from({ length: R }, () => new Array(C).fill(0));
const p = Array.from({ length: R * C }, (_, i) => i);

const mv = [
  [1, 0],
  [1, -1],
  [1, 1],
  [0, 1],
  [0, -1],
  [-1, 0],
  [-1, 1],
  [-1, -1],
];

const move = (r, c) => {
  let minVal = arr[r][c];
  const ansLoc = [-1, -1];

  for (const [dr, dc] of mv) {
    const nr = r + dr;
    const nc = c + dc;
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

    if (arr[nr][nc] < minVal) {
      minVal = arr[nr][nc];
      ansLoc[0] = nr;
      ansLoc[1] = nc;
    }
  }
  return ansLoc;
};

const toNum = (r, c) => {
  return r * C + c;
};
const toLoc = (num) => {
  return [Math.floor(num / C), num % C];
};

const parent = (num) => {
  if (p[num] === num) return num;
  let end = p[num];
  while (end !== p[end]) end = p[end];
  while (num !== end) {
    const nxt = p[num];
    p[num] = end;
    num = nxt;
  }
  return end;
};

const unite = (a, b) => {
  a = parent(a);
  b = parent(b);
  if (a === b) return false;
  const [ar, ac] = toLoc(a);
  const [br, bc] = toLoc(b);

  if (arr[ar][ac] < arr[br][bc]) {
    p[b] = a;
  } else {
    p[a] = b;
  }

  return true;
};

for (let i = 0; i < R; ++i) {
  for (let j = 0; j < C; ++j) {
    const [nxtR, nxtC] = move(i, j);
    if (nxtR === -1) continue;
    const a = toNum(i, j);
    const b = toNum(nxtR, nxtC);
    unite(a, b);
  }
}

for (let i = 0; i < R; ++i) {
  for (let j = 0; j < C; ++j) {
    const pLoc = parent(toNum(i, j));
    const [pr, pc] = toLoc(pLoc);
    ans[pr][pc]++;
  }
}
for (const line of ans) {
  console.log(...line);
}
