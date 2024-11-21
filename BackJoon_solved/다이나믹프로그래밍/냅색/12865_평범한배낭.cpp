#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int dp[101][100001];
//dp[i][j] : 물건이 i개까지 넣은 경우 , 무게가 j일때 최대 가치

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,max_weight;
    cin >> N >> max_weight;

    vector<pair<int,int>> dt(N+1); //N개 물품 , <무게 , 가치 >
    for (int i=1;i<=N;i++) {
        cin >> dt[i].first >> dt[i].second ;
    }

    sort(dt.begin(),dt.end());

    //물건을 넣을 수 없는 경우 : dp[i-1][j] 그대로
    //넣을수 있는 경우 : dp[i-1][j] , dp[i-w[i]]+v[i] 의 값 비교

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=max_weight;j++) {
            if (j>=dt[i].first) {
                dp[i][j] = max (dp[i-1][j], dp[i-1][j-dt[i].first] +dt[i].second );
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[N][max_weight];

    
    return 0;
}