// 1차원
const arr1 = new Array(3);
// console.log(arr1); // 배열 크기 3개

// 입력받은 모든 원소 배열화
const arr2 = new Array(3, 2, { 1: "abc", 2: 123, 3: null });
// console.log(arr2); // [ 3, 2, { '1': 'abc', '2': 123, '3': null } ]

// 2차원
const arr2D_1 = new Array(5);
for (let i = 0; i < 5; ++i) {
  arr2D_1[i] = new Array(2);
}
// console.log(arr2D_1); // 행 5, 열 2개
// [
//     [ <2 empty items> ],
//     [ <2 empty items> ],
//     [ <2 empty items> ],
//     [ <2 empty items> ],
//     [ <2 empty items> ]
//   ]

const arr2D_2 = Array.from(new Array(2), () => Array(3).fill(0));
// console.log(arr2D_2);
// [ [ 0, 0, 0 ], [ 0, 0, 0 ] ]

// 3차원
const arr3D_1 = Array.from(new Array(2), () => Array(5).fill(new Array(4)));
// console.log(arr3D_1);
// [
//     [
//       [ <4 empty items> ],
//       [ <4 empty items> ],
//       [ <4 empty items> ],
//       [ <4 empty items> ],
//       [ <4 empty items> ]
//     ],
//     [
//       [ <4 empty items> ],
//       [ <4 empty items> ],
//       [ <4 empty items> ],
//       [ <4 empty items> ],
//       [ <4 empty items> ]
//     ]
//   ]

const arr3D_2 = Array.from(new Array(2), () =>
  Array(5).fill(Array.from(new Array(4), () => 0))
);
// console.log(arr3D_2);
// [
//     [
//       [ 0, 0, 0, 0 ],
//       [ 0, 0, 0, 0 ],
//       [ 0, 0, 0, 0 ],
//       [ 0, 0, 0, 0 ],
//       [ 0, 0, 0, 0 ]
//     ],
//     [
//       [ 0, 0, 0, 0 ],
//       [ 0, 0, 0, 0 ],
//       [ 0, 0, 0, 0 ],
//       [ 0, 0, 0, 0 ],
//       [ 0, 0, 0, 0 ]
//     ]
//   ]

// For 구문
const arr3 = [1, 3, 2, 4, 5, 1];
for (let a of arr3) {
  // console.log(a);
}
// 1
// 3
// 2
// 4
// 5
// 1

const arr4 = [
  [1, 2],
  [2, 3],
];
for (const [a, b] of arr4) {
  // console.log(a, b);
}
// 1 2
// 2 3
// console.log("-------");
const arr5 = [
  [1, 2, 3],
  [4, 5, 6],
];
for (const [a, b] of arr5) {
  // console.log(a, b);
}
// 1 2
// 4 5
for (const [a, ...b] of arr5) {
  // console.log(a, b);
}
// 1 [ 2, 3 ]
// 4 [ 5, 6 ]

// ---- find
const arr6 = [1, 2, 3, 10, 5];
console.log(arr6.find((item) => item == 10)); //10
console.log(arr6.find((item) => item == 4)); //undefined

// index
console.log(arr6.findIndex((item) => item === 10)); // 3
console.log(arr6.findIndex((item) => item === 123)); // -1
