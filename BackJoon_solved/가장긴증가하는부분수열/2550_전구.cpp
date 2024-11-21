#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int dp[100000]; //
bool is_lis[100000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N ; cin >> N;
    vector<int> datas(N+1); // 해당 인덱스 번호 = 스위치 번호, 저장값 = 그 자리 인덱스 위치
    vector<int> light(N+1); //헤당하는 인덱스 값 = 전구번호, 저장값 = 해당 인덱스 (위에서 아래로 번호)
    vector<pair<int, int> > comb(N+1);//실제 번호들 연결 (스위치 번호 , 전구 번호) ,인덱스 = 스위치 인덱스 위치
    vector<int> idx_connect(N+1); //스위치 인덱스 번호가 이 벡터의 인덱스 = 저장값 해당 위치가 어느 전구의 인덱스에 있는가?
    vector<int> L; //LIS연산용
    vector<int>::iterator it;
    vector<int> st;
    int dp[100001];

    int temp;
    for (int i = 1 ; i <= N ; i++ ) {
        cin >> temp; datas[temp] = i;
        comb[i].first = temp; }
    for (int i = 1 ; i <= N ; i++ ) {
        cin >> temp; light[temp] = i;
        comb[i].second = temp;
    }
    for (int i = 1 ; i <=N ;i++) {
        idx_connect[i] = light[ comb[i].first ];
    }

    int max_len = 0 , idx =-1;
    //LIS연산 with 
    for (int i = 1 ; i <= N ; i++) {
        if (L.empty() || L.back() < idx_connect[i]) {
            L.push_back(idx_connect[i]);
            dp[i] = L.size();
        }
        else {
            it = lower_bound(L.begin(),L.end(),idx_connect[i]);
            *it = idx_connect[i];
            dp[i] = (it - L.begin())+1;
        }
        if (max_len < dp[i]) {max_len = dp[i]; idx = i;}
    }
    cout << max_len << '\n';
    for (int i = idx; i >= 1 ; i--) {
        if (max_len==0) break;
        if (max_len == dp[i]) {
            st.push_back(comb[i].first);
            max_len--;
        }
    }
    sort(st.begin(),st.end());
    for (auto e :st) {
        cout << e << ' ';
    }
}