#include <iostream>
#include <cstring>
#include <set>
#include <unordered_map>
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int inf = 1e9+7;
int n, q;
int inp[100001];
int arr[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tmp;
    int a, b; 
    set<int> s;
    unordered_map<int, int> grid;
    cin >> n >> q;
    f(i,1,n+1) cin >> inp[i];
    inp[0] = -inf;
    sort(inp, inp+n+1);
    f(i,1,n+1) grid[inp[i]] = i;
    f(i,1,n+1) arr[grid[inp[i]]]++;
    f(i, 1, n+1) arr[i] += arr[i-1];
    while (q--)
    {
        cin >> a >> b;

        int a_loc = lower_bound(inp, inp+n+1, a) - inp;
        int b_loc = upper_bound(inp, inp+n+1, b) - inp;
        b_loc--;

        cout << arr[b_loc] - arr[a_loc - 1] << '\n';
    }
    

    return 0;   
}