#include <iostream>
#include <vector>
#include <algorithm>
#define INF 4000001
using namespace std;

int table[401][401];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int V, E; cin >> V >> E;
    for (int i = 1 ; i <= V ; i++) {
        for (int j = 1 ; j <= V ;j++) {
            table[i][j] =INF;
        }
        table[i][i] = 0;
    }
    int start, end, cost;
    for (int i = 0 ; i < E ; i++) {
        cin >> start >> end >> cost;
        table[start][end] = cost;
    }

    for (int i = 1 ; i <= V ; i++) {//경유지
        for (int j = 1 ; j <= V ; j++) {
            for (int k = 1 ; k <= V ; k++) { //j,k : 시작 -> 종료
                table[j][k] = min(table[j][k] , table[j][i] + table[i][k]);
            }
        }
    }
    int result = INF;
    for (int i = 1 ; i <= V ; i++) {
        for (int j = 1 ; j <= V ; j++) {
            if( i == j) continue;
            result = min(result, table[i][j] + table[j][i]);
        }
    }
    cout << ((result >= INF )? -1 : result);
    return 0;
}