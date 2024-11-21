#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int city[201];

int find(int n) {
    if (city[n] == n) return n;
    return city[n] = find(city[n]);
}
void _union(int a, int b) {
    int px = find(a);
    int py = find(b);

    if (px > py) city[px] = py;
    else city[py] = px;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >>N;
    int M ; cin >>M;
    int inp;
    for (int i = 1; i <= N; i++) {
        city[i]  = i;   }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N ; j++) {
            cin >> inp;
            if (inp == 1) _union(i,j);
        }
    }

    int past; cin >> past;
    int loc = find(past);
    for (int i = 1 ; i <M; i++) {
        cin >> past;
        if (loc != find(past)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES"; return 0;

}