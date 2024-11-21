#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool dp[31][15001]; // i 개의 추 가지고 무게 n 구현이 가능한가?
int weight[31]; //무게추들

void check(int i, int w) {
    if (i > n || dp[i][w]) return ; //이미 확인되었거나, 값 초과시 리턴

    dp[i][w] = true;

    //추 1개 추가시, 만들 수 있는 무게 전부 등록, 이때 추를 안 넣는 경우도 고려
    check(i+1, w + weight[i]);
    check(i+1, abs( w - weight[i]));
    check(i+1, w);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> weight[i];
    }
    check(0,0);

    int p,temp; cin >> p;

    for (int i = 0 ; i < p; i ++) {
        cin >> temp;
        if (temp > 15000) cout << "N ";
        else if (dp[n][temp]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}