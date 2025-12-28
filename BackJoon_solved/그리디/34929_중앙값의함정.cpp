#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct info
{
    int a, b, c;
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<int> inp_lst(n);
    for (int &a : inp_lst) cin >> a;
    sort(inp_lst.begin(), inp_lst.end());

    cout << inp_lst[ max(0, n-2 ) ] << '\n';
    
    deque<int> dq; dq.assign(n, 0);
    for(int i = 0; i < n; ++i) dq[i] = inp_lst[i];

    while (dq.size() > 1)
    {
        int a = dq.front(); dq.pop_front();
        int b = dq.front(); dq.pop_front();
        int c = dq.front(); dq.pop_front();

        cout << a << ' ' << b << ' ' << c << '\n';

        dq.push_front(b);
    }


    return 0;
}