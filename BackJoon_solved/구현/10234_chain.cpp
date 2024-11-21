#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int H;
deque<int> dt[5]; // H-1 -> 0 으로 입력할 것
int input[5];

vector<pair<int, int> > eraselst;

int check(void) {
    int result = 0;
    int k;
    bool found = false;
    for (int hloc = 0 ; hloc < H ; hloc++) {
        found = true;
        for (int len = 5 ; len >=3 ; len--) {//길이
            for (int st = 0; st <= (5- len) ; st++) {//시작점
                for (k = 0 ; k < len-1 ; k++) {
                    if (dt[hloc][st+k] != dt[hloc][st+k+1]) {
                        found = false;
                        break;
                    }
                }
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true) {
        cin >> H;
        if (H == 0) break;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < 5 ; j++) cin >> input[i];
            for (int j = 0; j < 5 ; j++) dt[j].push_back(input[i]);


        }
    }
}