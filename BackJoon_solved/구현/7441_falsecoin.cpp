#include <iostream>
#include <vector>
using namespace std;

int coin_state[101]; //0 : 미확인, 1: 진품 , 2 : 의심품

int main(void) {
    int N, K; cin >> N >> K;
    int cnt, inp; char result;  
    vector<int> left, right;
    while (K--) {
        cin >> cnt;
        for (int i = 0; i < cnt ; i++) {
            cin >> inp; left.push_back(inp);
        }
        for (int i = 0; i < cnt ; i++) {
            cin >> inp; right.push_back(inp);
        }
        cin >> result;

        if (result == '=') {
            for (int i = 0; i < cnt ; i++) {
                coin_state[left[i]] = 1;
                coin_state[right[i]] = 1;
            }
        }
        else if (result == '<' || result == '>') {
            for (int i = 0; i < cnt ; i++) {
                if (coin_state[left[i]] == 0) coin_state[left[i]] = 2;
                if (coin_state[right[i]] == 0) coin_state[right[i]] = 2;
            }

            for (int i = 1 ; i <= N ;i++) {
                if (coin_state[i] != 2) coin_state[i] = 1;
            }
        }
        left.clear(); right.clear();
    }
    vector<int> false_list;
    for (int i = 1 ; i <= N ; i++) {
        if (coin_state[i] == 2 || coin_state[i] == 0) false_list.push_back(i);
    }

    if (false_list.size() == 1) {
        cout << false_list[0];
    }
    else {
        cout << 0;
    }
    return 0;
}