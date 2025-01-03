class Heap {
  // 비교함수, (a가 b보다 작은 경우 음수)
  constructor(compareFn = (a, b) => a - b) {
    this.heap = [];
    this.comp = compareFn;
  }
  isEmpty() {
    return this.heap.length === 0;
  }

  swap(idx1, idx2) {
    [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]];
  }

  heapifyUp() {
    let index = this.heap.length - 1;
    let parentIndex = Math.floor((index - 1) / 2);

    while (
      index > 0 &&
      this.comp(this.heap[parentIndex], this.heap[index]) > 0
    ) {
      this.swap(index, parentIndex);
      index = parentIndex;
      parentIndex = Math.floor((index - 1) / 2);
    }
  }

  heapifyDown() {
    const length = this.heap.length;
    let index = 0;
    let leftChild = 0;
    let rightChild = 0;
    let minChild = 0;

    while (true) {
      leftChild = 2 * index + 1;
      rightChild = 2 * index + 2;
      minChild = index;

      if (
        leftChild < length &&
        this.comp(this.heap[leftChild], this.heap[minChild]) < 0
      ) {
        minChild = leftChild;
      }
      if (
        rightChild < length &&
        this.comp(this.heap[rightChild], this.heap[minChild]) < 0
      ) {
        minChild = rightChild;
      }
      if (minChild == index) break;
      this.swap(minChild, index);
      index = minChild;
    }
  }

  push(item) {
    this.heap.push(item);
    this.heapifyUp();
  }
  pop() {
    if (this.isEmpty()) return null;
    if (this.heap.length === 1) {
      // 힙에 원소가 하나만 있을 경우
      return this.heap.pop();
    }

    const root = this.heap[0];
    this.swap(this.heap.length - 1, 0);

    this.heap.pop();
    this.heapifyDown();
    return root;
  }
  top() {
    if (this.isEmpty()) return null;
    return this.heap[0] || null;
  }
}

const heap = new Heap();
heap.push(3);
console.log(heap.heap);

heap.push(2);
console.log(heap.heap);

heap.push(12);
console.log(heap.heap);

heap.push(10);
console.log(heap.heap);

heap.push(-5);
console.log(heap.heap);

for (let i = 0; i < 5; ++i) {
  console.log(heap.pop());
}
