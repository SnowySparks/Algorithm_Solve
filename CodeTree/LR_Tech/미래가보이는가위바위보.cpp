#include <iostream>
#include <cstring>
#define f(a, b, c) for(int a = b; a < c; ++a)
using namespace std;
const int H = 0, S = 1, P = 2; // 주먹, 가위 , 보자기
int n;
char ch;
const int inf = 1e5+2;
int arr[inf];
int ldp[inf], rdp[inf]; // 
// ldp : 1 ~ idx범위 내에서 주먹 가위 보자기 중 가장 많이 낸 수 


int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 1, n+1) {
        cin >> ch;
        switch (ch)
        {
        case 'H':
            arr[i] = 0;
            break;
        case 'S':
            arr[i] = 1;
            break;
        case 'P':
            arr[i] = 2;
            break;
        }
    }

    int ans = -1;
    f(st, 0, 3) {
        int cnt = 0;
        f(i, 1, n+1) {
            if (st == arr[i]) ++cnt;
            ldp[i] = max(ldp[i], cnt);
        }
    }
    f(st, 0, 3) {
        int cnt = 0;
        for(int i = n; i >= 1; --i) {
            if (st == arr[i]) ++cnt;
            rdp[i] = max(rdp[i], cnt);
        }
    }

    f(i, 0, n+1) {
        ans = max(ans, ldp[i] + rdp[i+1]);
    }
    cout << ans;
    return 0;
}