#include <iostream>
#include <list>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    list<pair<int, long long> > lst;
    for (int i = 1; i <= n; ++i) {
        int sz; cin >> sz;
        lst.push_back({i, sz});
    }

    while (lst.size() > 1)
    {
        list<pair<int, long long>>::iterator it = lst.begin();
        while (it != lst.end())
        {
            long long origin_size = it->second;
            if (it != lst.begin()) {
                list<pair<int, long long>>::iterator left = prev(it);
                if (left->second <= origin_size) {
                    it->second += left->second;
                    lst.erase(left);
                }
                
            }
            if (it != prev(lst.end()) ) {
                list<pair<int, long long>>::iterator right = next(it);
                if (right->second <= origin_size) {
                    it->second += right->second;
                    lst.erase(right);
                }
            }
            it = next(it);
        }
    }
    pair<int, long long> ans = lst.front();
    cout << ans.second << '\n' << ans.first;
    return 0;
}