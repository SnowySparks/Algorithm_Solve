#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int table[1000001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int a,b,inp;
    unordered_map<int,int> tb;
    while (T--) {
        cin >> a;
        for (int i = 1; i <= a; i++) cin >> table[i];
        sort(table+1,table+1+a);
        cin >> b;
        while (b--) {cin >> inp;
            if(binary_search(table+1,table+1+a,inp)) cout <<'1'<<'\n';
            else cout << '0'<<'\n';
        }   
    }
    return 0;
}