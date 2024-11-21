#include <iostream>
#include <cstring>
using namespace std;
int loc[10000];
bool isused[10000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int L, C, K; cin >> L >> K >> C;
    //l : 통나무 길이, c : 통나무 자를 수 있는 최대 횟수, k = 위치갯수
    for (int i = 0 ; i < K; ++i) cin >> loc[i];
    int l = 1, r = L;
    while (l <= r) {
        int mid = (l+r)>>1;
        memset(isused,0,sizeof(isused));
    }
    return 0;
}