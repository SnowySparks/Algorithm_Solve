class Node {
  constructor(item) {
    this.next = null;
    this.item = item;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.tail = null;
  }
  empty() {
    return this.head === null;
  }
  push(item) {
    const node = new Node(item);
    if (this.empty()) {
      this.head = node;
      this.tail = node;
    } else {
      this.tail.next = node;
      this.tail = node;
    }
  }
  pop() {
    if (this.empty()) return null;
    const item = this.head.item;
    this.head = this.head.next;

    if (this.empty()) {
      this.tail = null;
    }
    return item;
  }
  clear() {
    while (!this.empty()) this.pop();
  }
}

const INF = 10 ** 9 + 7;

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let lineIdx = 0;

const [n, m] = input[lineIdx++].split(" ").map((a) => Number(a));
const gh = Array.from(Array(n), () => {
  return input[lineIdx++].split(" ").map((a) => Number(a));
});

const portal = new Map();
const mv = [
  [1, 0],
  [-1, 0],
  [0, 1],
  [0, -1],
];

let presentR, presentC; //선물 위치
for (let r = 0; r < n; ++r) {
  for (let c = 0; c < m; ++c) {
    if (gh[r][c] == -2) {
      presentR = r;
      presentC = c;
    } else if (gh[r][c] >= 10) {
      if (!portal.get(gh[r][c])) {
        portal.set(gh[r][c], []);
      }
      portal.get(gh[r][c]).push([r, c]);
    }
  }
}

const v1 = Array.from(Array(n), () => Array(m).fill(-1));
const v2 = Array.from(Array(n), () => Array(m).fill(-1));

// 1번째 선물상자로 이동하기
v1[0][0] = 0;
const q = new Queue();
q.push([0, 0]);
let cost = 0;

const enablePortal = new Set();
let fd = false;
while (true) {
  while (!q.empty()) {
    const [r, c] = q.pop();
    if (r == presentR && c == presentC) {
      fd = true;
      break;
    }
    for (const [dr, dc] of mv) {
      const [nr, nc] = [r + dr, c + dc];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
      if (gh[nr][nc] == -1) continue;
      if (v1[nr][nc] != -1) continue;

      v1[nr][nc] = cost;
      q.push([nr, nc]);
      if (gh[nr][nc] >= 10) enablePortal.add(gh[nr][nc]);
    }
  }
  if (fd) break;

  if (enablePortal.size === 0) break;
  for (const portalNum of enablePortal) {
    for (const [pr, pc] of portal.get(portalNum)) {
      if (v1[pr][pc] === -1) {
        v1[pr][pc] = cost + 1;
        q.push([pr, pc]);
      }
    }
  }
  enablePortal.clear();
  ++cost;
}

v2[presentR][presentC] = 0;
enablePortal.clear();
q.clear();
q.push([presentR, presentC]);

fd = false;
cost = 0;
while (true) {
  while (!q.empty()) {
    const [r, c] = q.pop();
    if (r == n - 1 && c == m - 1) {
      fd = true;
      break;
    }
    for (const [dr, dc] of mv) {
      const [nr, nc] = [r + dr, c + dc];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
      if (gh[nr][nc] == -1) continue;
      if (v2[nr][nc] != -1) continue;

      v2[nr][nc] = cost;
      q.push([nr, nc]);
      if (gh[nr][nc] >= 10) enablePortal.add(gh[nr][nc]);
    }
  }
  if (fd) break;

  if (enablePortal.size === 0) break;
  for (const portalNum of enablePortal) {
    for (const [pr, pc] of portal.get(portalNum)) {
      if (v2[pr][pc] === -1) {
        v2[pr][pc] = cost + 1;
        q.push([pr, pc]);
      }
    }
  }
  enablePortal.clear();
  ++cost;
}

if (v1[presentR][presentC] == -1 || v2[n - 1][m - 1] == -1) {
  console.log(-1);
} else {
  console.log(v1[presentR][presentC] + v2[n - 1][m - 1]);
}
