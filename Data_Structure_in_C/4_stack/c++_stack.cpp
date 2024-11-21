#include<iostream>

template<typename T>
class stack {
    private:
        T *arr;
        int top_loc;
        int capacity;
    public:
        stack(int size = 128) {
            arr = new T[size];
            top_loc = -1;
            capacity = 128;
        }
        ~stack() {
            delete arr;
        }
        bool isEmpty() {
            return top_loc==-1? true:false;
        }
        bool isFull() {
            return top_loc==capacity-1;
        }
        void push(T data) {
            if (isFull()) {
                T* another_arr = new T[capacity*2];
                for (int i = 0 ; i < capacity; ++i) {
                    another_arr[i] = arr[i];
                }
                T *temp;
                arr = temp;
                arr = another_arr;
                delete temp;
            }

            arr[++top_loc] = data;
        }
        T pop() {
            if (isEmpty()) {
                delete arr;
                throw std::invalid_argument("Tried to pop empty stack");
                }
            else {
                return arr[top_loc--];
            }
        }
        T top() {
            return arr[top_loc];
        }

};

int main(void) {
    stack<int> st(122);
    st.push(12);
    st.push(123);
    std::cout << st.pop();
    std::cout << st.pop();
    
    return 0;
}