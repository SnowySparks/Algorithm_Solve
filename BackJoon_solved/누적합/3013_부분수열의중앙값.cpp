#include <iostream>
#include <unordered_map>
using namespace std;
int n, b, ar[100000],loc,sum = 0, ans = 1;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> b;
    unordered_map<int, int> li, ri;
    for (int i = 0 ; i < n; i++) {
        cin >> ar[i]; 
        if (ar[i] > b) ar[i] = 1;
        else if (ar[i] < b) ar[i] = -1;
        else {ar[i] = 0; loc = i;} 
    }
    for (int i = loc -1 ; i >= 0 ; i--) {
        sum += ar[i];
        li[sum]++;
    }
    sum = 0;
    for (int i = loc + 1 ; i < n ; i++) {
        sum+= ar[i];
        ri[sum]++;
    }
    for (pair<int,int> a : li) {
        if (a.first!= 0 && ri.find(-a.first)!=ri.end()) ans+= li[a.first]*ri[-a.first];
        }
    ans += li[0] + ri[0] + li[0] * ri[0];
    cout << ans; return 0;

}
