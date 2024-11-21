#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int cal(vector<int> &lst) {
    sort(lst.begin(),lst.end());
    if (lst.size() == 0) return 0;
    if (lst.size() <= m) return lst.back();
    int res = lst.back();
    int loc = (int)lst.size() - m -1;
    while (loc > 0) {
        res += lst[loc]*2;
        loc-=m;
    }
    return res;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    vector<int> pl(1,0),mu(1,0);
    for (int i = 0 ; i < n ; i++) {
        int inp; cin >> inp;
        if (inp > 0) pl.push_back(inp);
        else mu.push_back(-inp);
    }
    cout << cal(pl) + cal(mu) + min(pl.back(),mu.back());
    return 0;
}