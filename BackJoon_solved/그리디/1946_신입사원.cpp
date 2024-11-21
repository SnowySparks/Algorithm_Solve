#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool srt(const pair<int, int>& a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    vector<pair<int, int> > V;
    while(T--) {
        int n; cin >> n;
        int cnt = 0; //합격인원
        pair<int, int> inp;
        for (int i = 0; i < n ; i++) {
            cin >> inp.first >> inp.second;
            V.push_back(inp);
        }
        sort(V.begin(), V.end(),srt);
        int min_first = V[0].first;
        int min_sec = 10000000;
        for (int i = 0 ; i < n ; i++) {
            if (min_first == V[i].first) { //서류 1등은 전부 카운트
                cnt++;
                min_sec = V[i].second;
            }
            else { //서류 2등부터 , 면접 순위를 갱신하면서 계산
                if (min_sec > V[i].second) {
                    cnt++;
                    min_sec = V[i].second ;
                }
            }
        }
        cout << cnt <<'\n';
        V.clear();
    }
}