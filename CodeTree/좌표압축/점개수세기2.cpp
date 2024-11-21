#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#define X 0
#define Y 1
#define f(a, b, c) for (int a = b; a<c;++a)
using namespace std;
const int inf = 1e9+7;
const int max_n = 2500;
int n, q;

int arr[max_n+1][max_n+1];
int inp[max_n+1][2];
int cord[2][max_n+1];

int cnt[2] = {1, 1};
unordered_set<int> tmp;
unordered_map<int, int> xmap;
unordered_map<int, int> ymap;

int lower_find(int val, int state) { 
    int loc = lower_bound(cord[state], cord[state] + cnt[state], val) - cord[state];
    return loc;
}

int upper_find(int val, int state) { 
    int loc = upper_bound(cord[state], cord[state] + cnt[state], val) - cord[state];
    return loc-1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> q;
    f(i, 0, n) cin >> inp[i][0] >> inp[i][1];

    // x자리 처리
    f(i, 0, n) tmp.insert(inp[i][0]);
    cord[0][0] = -inf;
    for (int val : tmp) {
        cord[0][cnt[0]++] = val;
    }
    sort(cord[0], cord[0] + cnt[0]);

    tmp.clear();
    // y자리 처리
    f(i, 0, n) tmp.insert(inp[i][1]);
    cord[1][0] = -inf;
    for (int val : tmp) {
        cord[1][cnt[1]++] = val;
    }
    sort(cord[1], cord[1] + cnt[1]);

    // 좌표압축
    f(i, 1, cnt[0]) xmap[cord[0][i]] = i;
    f(i, 1, cnt[1]) ymap[cord[1][i]] = i;

    // prefix sum
    f(i, 0, n) {
        // cout << "x :" << inp[i][0] <<"->" << xmap[inp[i][0]] << '\n';
        // cout << "y :" << inp[i][1] <<"->" << ymap[inp[i][1]] << '\n';
        arr[ xmap[ inp[i][0] ] ][ ymap[ inp[i][1] ] ] ++;
    }
    f(r, 1, n+1) f(c, 1, n+1) {
        arr[r][c] += arr[r-1][c] + arr[r][c-1] - arr[r-1][c-1];
    }

    int x1, x2, y1, y2;
    // query
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        int x1_loc = lower_find(x1, X);
        int x2_loc = upper_find(x2, X);
        int y1_loc = lower_find(y1, Y);
        int y2_loc = upper_find(y2, Y);

        // cout << x1_loc << ' ' << y1_loc <<' ' << x2_loc <<' ' << y2_loc << '\n';

        cout << arr[x2_loc][y2_loc] - arr[x1_loc-1][y2_loc] - arr[x2_loc][y1_loc-1] + arr[x1_loc-1][y1_loc-1] << '\n';
    }
    


    return 0;
}