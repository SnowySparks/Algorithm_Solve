#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define inf 9876543

int gh[50][50];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    string inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        for (int j = 0; j < N ; j++) {
            gh[i][j] = inf;
            if (inp[j] == 'Y') gh[i][j] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i==j || j == k || k == i) continue;
                gh[j][k] = min(gh[j][k],gh[j][i]+gh[i][k]);
            }
        }
    }

    int answer = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i!=j && gh[i][j] <= 2) cnt++;
        }
        answer = max(answer,cnt);
    }
    cout << answer; return 0;

}