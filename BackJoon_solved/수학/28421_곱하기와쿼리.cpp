#include <iostream>
#include <cmath>
#include <map>
using namespace std;
const int p = 1e5+1;
#define f(a,b,c) for(int a=b;a<=c;a++)

int arr[p];
int len = 0;
map<int, int> lst;

bool canfind(int n) {
    if (len == 1) return 0;
    int end = (int) sqrt(n);

    if (n == 0) return (lst[0] ? true : false);

    for (auto e : lst) {
        if (e.first == 0) continue;
        if (e.first > end) break;
        if (n%e.first || e.second == 0) continue;
        if (lst.find(n/e.first)!=lst.end()) {
            if (e.first == n/e.first ) return (e.second >= 2 ? true : false);
            else return (lst[n/e.first] > 0 ? true : false);
        }
    }
    return false;
}

void done(int loc) {
    if (arr[loc]) {lst[arr[loc]]--; arr[loc] = 0; lst[0]++;}
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q; len = n;
    f(i,1,n) {
        cin >> arr[i];
        lst[arr[i]]++;
    }
    int quest, num;
    while (q--) {
        cin >> quest >> num;
        if (quest == 1) cout << (canfind(num) ? 1 : 0) << "\n";
        else done(num);
    }
    return 0;
}