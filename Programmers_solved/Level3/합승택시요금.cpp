#include <string>
#include <vector>
#include <algorithm>
#define INF 2000000

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int > > tb (n+1, vector<int> (n+1, INF));
    for (int i = 1 ; i <= n ; i++) {
        tb[i][i] = 0;
    }
    for (auto e : fares) {
        tb[e[0]][e[1]] =e[2];
        tb[e[1]][e[0]] = e[2];
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            for (int k = 1 ; k <= n ; k++) {
                tb[j][k] = min(tb[j][k],tb[j][i]+tb[i][k]);
            }
        }
    }
    answer = min(answer,tb[s][a]+tb[s][b]);
    for (int i = 1 ; i <= n ; i++) {
        answer = min (answer , tb[s][i]+tb[i][a]+tb[i][b]);
    }
    return answer;
}