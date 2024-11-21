#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;

int n, q; // 노선 수 , query
vector<vector<int> > line; // [i][k], i호선에 k 번째 역 번호 저장
vector<int> cnt; // i호선에 역의 모든 개수.
unordered_map<string, int> st_num; // station_number for 좌표압축
unordered_map<int, int> cross_num; // 환승역들의 추가 부여 번호

string inp; int cnt;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    line.assign(n+1,vector<int>);
    cnt.assign(n+1,0);
    for (int i = 1 ; i <= n ; i++) {
        cin >> cnt;

        for (int k = 0 ; k < cnt ; k++) {
            cin >> inp;
            if (st_num.find(inp)==st_num.end()) st_num[inp] = (int(st_num.size()))+1;
            else {
                if (corss_num.find(inp)==cross_num.end()) cross_num[st_num[inp]] = (int)cross_num.size()+1;
            }
            line[i].push_back(st_num[inp]);
        }
    }
}