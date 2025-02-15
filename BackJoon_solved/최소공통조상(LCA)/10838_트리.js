const fs = require("fs");

const input = fs
  .readFileSync(process.platform == "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");
let lineInput = 0;

const [n, q] = input[lineInput++].split(" ").map((item) => Number(item));

parent = Array.from({ length: n + 1 }, (_, i) => {
  return i == 0 ? -1 : 0;
});
color = [...parent];
check = [...parent];

const find_lca = (a, b, k) => {
  if (a == 0 || b == 0) return 0;
  if (a == b) return a;
  for (let i = 0; i < 1000; ++i) {
    check[a] = k;
    a = parent[a];
    if (a == -1) break;
  }
  for (let i = 0; i < 1000; ++i) {
    if (check[b] === k) return b;
    check[b] = k;
    b = parent[b];
    if (b == -1) break;
  }
  return 0;
};

const set = new Set();

for (let query = 1; query <= q; ++query) {
  const [r, ...values] = input[lineInput++].split(" ").map((e) => Number(e));

  const a = values[0];
  const b = values[1];

  if (r == 1) {
    const lca = find_lca(a, b, query);
    for (let node = a; node != lca; node = parent[node])
      color[node] = values[2];
    for (let node = b; node != lca; node = parent[node])
      color[node] = values[2];
  } else if (r == 2) {
    parent[a] = b;
  } else {
    const lca = find_lca(a, b, query);
    set.clear();
    for (let node = a; node != lca; node = parent[node]) set.add(color[node]);
    for (let node = b; node != lca; node = parent[node]) set.add(color[node]);
    console.log(set.size);
  }
}
