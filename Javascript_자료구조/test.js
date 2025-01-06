class Heap {
  constructor(compareFn = (a, b) => a - b) {
    this.heap = [];
    this.compareFn = compareFn;
  }

  isEmpty() {
    return this.heap.length === 0;
  }

  swap(idx1, idx2) {
    [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]];
  }

  heapifyUp() {
    let idx = this.heap.length - 1;
    let parentIdx = Math.floor((idx - 1) / 2);

    while (
      idx > 0 &&
      this.compareFn(this.heap[parentIdx], this.heap[idx]) > 0
    ) {
      this.swap(parentIdx, idx);
      idx = parentIdx;
      parentIdx = Math.floor((idx - 1) / 2);
    }
  }

  heapifyDown() {
    const len = this.heap.length;
    let idx = 0;
    let Lchild = 2 * idx + 1;
    let Rchild = 2 * idx + 2;
    let minChild = 0;

    while (Lchild < len) {
      minChild = idx;
      if (this.compareFn(this.heap[minChild], this.heap[Lchild]) > 0)
        minChild = Lchild;
      if (
        Rchild < len &&
        this.compareFn(this.heap[minChild], this.heap[Rchild]) > 0
      )
        minChild = Rchild;

      if (minChild === idx) break;
      this.swap(idx, minChild);
      idx = minChild;
      Lchild = 2 * idx + 1;
      Rchild = 2 * idx + 2;
    }
  }

  push(item) {
    this.heap.push(item);
    this.heapifyUp();
  }
  pop() {
    const root = this.heap[0];
    this.swap(0, this.heap.length - 1);
    this.heap.pop();
    this.heapifyDown();
    return root;
  }
}

const heap = new Heap((a, b) => b - a);
heap.push(3);
heap.push(5);
heap.push(-1);
heap.push(123);
heap.push(-1234);

while (!heap.isEmpty()) {
  console.log(heap.pop());
}
