const fs = require("fs");
const [n, ...arr] = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((e) => Number(e));

let maxValue = 0;
let total = 0;
for (let num of arr) {
  maxValue = Math.max(num, maxValue);
  total += num;
}

if (maxValue >= total - maxValue) {
  console.log(2 * maxValue - total);
} else {
  console.log(total & 1);
}
