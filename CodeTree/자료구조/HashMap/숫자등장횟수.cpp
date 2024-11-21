#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<int, int> mp;
    int n, m; cin >> n >> m;
    int tmp;
    while (n--)
    {
        cin >> tmp;
        mp[tmp]++;
    }
    
    while (m--)
    {
        cin  >> tmp;
        cout << mp[tmp] <<' ';
    }
    

    return 0;
}