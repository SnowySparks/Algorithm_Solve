#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> gh[1001];
int iq[1001];

bool cmp(int a, int b) {
    return (iq[a] > iq[b]);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 1 ; i <= N ; i++) cin >> iq[i]; //iq;
    int a, b;
    for (int i = 0 ; i < N-1 ; i++) {//input adj 트리니까 한쪽으로 향하도록 해도 됨
        cin >> a >> b;
        gh[a].push_back(b);
    }
    // 한 노드 기준으로 동료들을 엮어 내기...(?)
    for (int i = 1 ; i <= N ; i++) {
        sort(gh[i].begin(), gh[i].end(), cmp);

        for (int k = 1 ; k < gh[i].size() ; k++) {
            cout << gh[i][k-1] << ' ' << gh[i][k] << '\n';
        }
        //마지막으로 상사랑 엮어내기?
        if (gh[i].size() > 0) cout << i << ' '<<gh[i][0] << '\n'; 
    }
    return 0;

}