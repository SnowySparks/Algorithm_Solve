const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");
let line = 0;
const n = Number(input[line++]);

const lst = Array.from({ length: n }, () => [0, 0]);
for (let i = 0; i < n; ++i) {
  const [a, b] = input[line++].split(" ").map((e) => Number(e));
  lst[i][0] = a;
  lst[i][1] = b;
}

lst.sort((a, b) => {
  return b[1] - a[1];
});

let lastTime = lst[0][1];
for (let i = 0; i < n; ++i) {
  const [duration, deadLine] = lst[i];
  if (deadLine < lastTime) lastTime = deadLine;
  lastTime -= duration;
}

if (lastTime < 0) lastTime = -1;
console.log(lastTime);
