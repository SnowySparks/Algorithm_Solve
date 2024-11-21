#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

long long dp[1500][10001];

int main(void) {
    int N, M; cin >> N >> M;
    deque<pair<int ,int> > datas; //무게 , 가치
    datas.push_back({0,0});
    int V,C,K,p;
    //개수를 1, 2 4 , 8 ... 노 나누어서 이를 한 묶음으로 처리해 별개의 상품으로 처리 
    for (int i = 1 ; i<= N ; i++) {
        cin >> V >> C >> K;
        p = 1;
        while (K>0) {
            datas.push_back({V*min(p,K), C*min(p,K)});
            K-=p; p=p*2;
        }   
    }
    int cnt = datas.size();
    for (int i = 1 ; i<= cnt ; i++) {
        for (int j = 1; j <= M; j++) {
            if (j >= datas[i].first) dp[i][j] = max(dp[i-1][j], dp[i-1][j-datas[i].first]+datas[i].second);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[cnt][M];

    return 0;
}