#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int arrived[100001]; //도착해 있으면 다음 작은 값 번호로 이동
//0으로 이동하면 마감

int find(int x) {
    if (arrived[x] == x) return x;
    return arrived[x] = find(arrived[x]);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int G, P; cin >> G >> P;
    vector<int> planes(P);
    int inp;
    int answer = 0;
    int loc;
    for (int i = 1 ; i <= 100000 ; i++) { arrived[i] = i ;}
    for (int i = 0 ; i < P ; i++) {
        cin >> planes[i];
    }
    for (int i = 0 ; i < P ; i++) {
        loc = find(planes[i]);
        if (loc != 0) {
            answer++;
            arrived[loc] = loc-1;
        }
        else break;
    }
    cout << answer; return 0;
}