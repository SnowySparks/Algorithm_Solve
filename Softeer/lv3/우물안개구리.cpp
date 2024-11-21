#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 1e5+1;
int n, m;
int weight[inf];
bool state[inf];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n ; ++i) {cin >> weight[i]; state[i] = true;}
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        if(weight[a] > weight[b]) {
            state[b]= false;
        }
        else if (weight[a] < weight[b]) {
            state[a] = false;
        }
        else {
            state[a] = false;
            state[b] = false;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (state[i]) ++cnt;
    }
    cout << cnt;
    return 0;
}