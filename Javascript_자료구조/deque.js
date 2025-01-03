class Node {
  constructor(item = null) {
    this.item = item;
    this.left = null;
    this.right = null;
  }

  static connect(leftNode, rightNode) {
    leftNode.right = rightNode;
    rightNode.left = leftNode;
  }
  static connectBetween(middleNode, leftNode, rightNode) {
    Node.connect(leftNode, middleNode);
    Node.connect(middleNode, rightNode);
  }
}

class Deque {
  constructor() {
    this.front = new Node();
    this.back = new Node();
    Node.connect(this.front, this.back);
    this._size = 0;
  }
  isEmpty() {
    return this._size === 0;
  }
  size() {
    return this._size;
  }
  addLeft(item) {
    const newNode = new Node(item);
    Node.connectBetween(newNode, this.front, this.front.right);
    this._size++;
  }
  addRight(item) {
    const newNode = new Node(item);
    Node.connectBetween(newNode, this.back.left, this.back);
    this._size++;
  }
  popLeft() {
    if (this.isEmpty()) throw new Error("popLeft: Deque is empty");

    const removeNode = this.front.right;
    Node.connect(this.front, removeNode.right);
    removeNode.left = removeNode.right = null;
    this._size--;

    return removeNode.item;
  }
  popRight() {
    if (this.isEmpty()) throw new Error("popRight: Deque is empty");

    const removeNode = this.back.left;
    Node.connect(removeNode.left, this.back);
    removeNode.left = removeNode.right = null;
    this._size--;

    return removeNode.item;
  }
  peekFront() {
    if (this.isEmpty()) throw new Error("peekFront: Deque is empty");
    return this.front.right.item;
  }
  peekBack() {
    if (this.isEmpty()) throw new Error("peekBack: Deque is empty");
    return this.back.left.item;
  }
}

const deque = new Deque();

deque.addLeft(3);
deque.addLeft(-123);
deque.addRight(1323132);
console.log(deque.peekFront());
console.log(deque.peekBack());
