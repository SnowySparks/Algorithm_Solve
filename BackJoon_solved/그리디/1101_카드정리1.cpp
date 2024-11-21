#include <iostream>
#include <cstring>
#define f(a,b,c) for(int a=b ; a < c ; a++)
using namespace std;

int n, m;
int cd[50][50],cnt[50];
bool v[50];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i,0,n) f(j,0,m) {
        cin >> cd[i][j];
        if (cd[i][j]) cnt[i]++;
    }

    int ans = n-1;

    f(i,0,n) {
        int p = 0;
        memset(v,0,sizeof(v));
        f(j,0,n) {
            if (i==j) continue;
            if (cnt[j] == 0) continue;
            else if (cnt[j] > 1) p++;
            else {
                f(k,0,m) {
                    if (cd[j][k]) {
                        if (!v[k]) v[k] = true;
                        else p++;
                        break;
                    }
                }
            }
        }
        ans = min (ans, p);
    }
    cout << ans;
 	return 0;
}