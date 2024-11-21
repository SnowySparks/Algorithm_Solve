#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template<typename T>
struct Node {
    Node *left, *right;
    T data;
};

template<typename T>
class Binary_Tree {
    private:
        Node<T>* root;
        Node<T> *SearchMaxNode(Node<T>* node) {
            if (node == nullptr) return nullptr;
            while (node->right != nullptr) {
                node = node ->right;
            } return node;
        }
        void postfix_output(Node<T> *Rt) {
            if (Rt == nullptr) return;
            postfix_output(Rt->left);
            postfix_output(Rt->right);
            cout << Rt->data <<'\n'; 
    }
    public:
        Binary_Tree() : root(nullptr) {}; 
        ~Binary_Tree() {};
        void AddNode(T _value);
        void print_bt() { postfix_output(root);}
};

template<typename T>
void Binary_Tree<T>::AddNode(T _value) {
    Node<T> *node = new Node<T>();
    Node<T> *temp = nullptr;
    node->data = _value;

    if (root == nullptr) root = node;
    else {
        Node<T> *ptr = root;
        while (ptr != nullptr) {
            temp = ptr;
            if (_value < ptr->data) {
                ptr= ptr->left;
            }
            else ptr= ptr->right;
        }
        if (node -> data < temp-> data) temp->left = node;
        else temp->right = node;
    }
}


int main(void) {
    int inp;
    Binary_Tree<int> *bst = new Binary_Tree<int>(); //할당
    while (cin >> inp) {// ctrl+D 로 강제종료 with mac
        bst->AddNode(inp);
    }
    bst->print_bt();
    return 0;
}
