#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];//누적합

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M; cin >> N >> M;
    for (int i = 0 ; i< N ; i++) {
        cin >> arr[i];
    }

    int a,b,c;
    while (M--) {
        cin >> a >> b >> c ;
        dp[a-1]+= c; dp[b]-=c;
    }

    for (int i = 1 ; i< N+1 ; i++) {
        dp[i] += dp[i-1]; 
    }

    for (int i = 0 ; i< N ; i++) {
        cout << arr[i] + dp[i] <<' ';
    }
    return 0;
} 