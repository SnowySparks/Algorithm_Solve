#include <iostream>
#include <vector>
#include <algorithm>
#define _inf 1<<28
using namespace std;

int gh[5001][5001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1; j <= N ; j++) {
            if (i == j) gh[i][j] = 0;
            else gh[i][j] = _inf;
        }
    }
    int a,b;
    while (M--) {  
        cin >> a >> b;
        gh[a][b] = 1;
        gh[b][a] = 1;
    }

    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= N ; j++) {
            for (int k = 1 ; k <= N ; k++) {
                gh[j][k] = min (gh[j][k], gh[j][i]+gh[i][k]);
            }
        }
    }

    int minimum = _inf;
    vector<int> lst;
    for (int i = 1 ; i <= N ; i++) {
        int cnt = 0;
        for (int j = 1 ; j <= N ; j++) {
            if (i!=j && gh[i][j] < _inf) cnt+=gh[i][j];
        }
        if (minimum > cnt ) {
            lst.clear();
            lst.push_back(i);
            minimum = cnt;
        }
        else if (minimum == cnt) {
            lst.push_back(i);
        }
    }
    cout << lst[0];
    return 0;
}