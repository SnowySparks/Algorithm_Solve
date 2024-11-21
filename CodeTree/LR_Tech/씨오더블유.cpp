#include <iostream>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
int n;
string s;
const int MAXN = 1e5;
long long l[MAXN], r[MAXN];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);  
    cin >> n;
    cin >> s;

    l[0] = (s[0] == 'C' ? 1 : 0);
    r[n-1] = (s[n-1] == 'W' ? 1 : 0);

    f(i, 1, n) {
        l[i] = l[i-1] + (s[i] == 'C' ? 1 : 0);
    }
    for (int i = n-2; i >= 0; --i) {
        r[i] = r[i+1] + (s[i] == 'W' ? 1 : 0);
    }

    long long ans = 0;
    f(i, 1, n-1) {
        if (s[i] == 'O') ans += l[i] * r[i];
    }
    cout << ans;
    return 0;
}