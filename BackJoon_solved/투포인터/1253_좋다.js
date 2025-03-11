const [[n], arr] = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((i) => i.split(" ").map((e) => Number(e)));

arr.sort((a, b) => a - b);
let answer = 0;
for (let idx = 0; idx < n; ++idx) {
  let done = false;
  let l = 0,
    r = n - 1;
  while (l < r) {
    if (l == idx) l++;
    if (r == idx) r--;
    if (l >= r) break;
    if (arr[l] + arr[r] == arr[idx]) {
      ++answer;
      break;
    } else if (arr[l] + arr[r] < arr[idx]) {
      l++;
    } else {
      r--;
    }
  }
}
console.log(answer);
