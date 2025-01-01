// input
const fs = require("fs");
const [a, ...input] = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((v) => {
    const d = v.split(" ");
    return d.map((e) => Number.parseInt(e));
  });

let [N, X] = a;
let ans = 0;
input.sort((a, b) => {
  // 5천원짜리, 1천원짜리 가치 갭이 가장 큰걸 우선으로 쓴다
  const a_x = a[0] - a[1];
  const b_x = b[0] - b[1];
  if (a_x !== b_x) return b_x - a_x;
  else return b[0] - b[1];
});

for (let i = 0; i < N; ++i) {
  // 만약에 지금 5000원 쓰고 나머지 전부 1000원 쓸 때 비용이 부족한 경우
  // 이 경우 무조건 1000원 써야한다
  if (X - 5000 - (N - i - 1) * 1000 < 0) {
    ans += input[i][1];
    X -= 1000;
  }
  //  1000원짜리가 더 맛있거나 같을경우
  else if (input[i][0] <= input[i][1]) {
    X -= 1000;
    ans += input[i][1];
  }
  //   5000원짜리가 더 맛있는 경우
  else {
    X -= 5000;
    ans += input[i][0];
  }
}

console.log(ans);
