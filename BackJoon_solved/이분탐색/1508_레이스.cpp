#include <iostream>
#include <vector>
#include <string>
#define F(a,b) for (int i = a; i < b; i++)
using namespace std;
const int M = 1E6;
int dt[M];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    F(0,K) cin >> dt[i];
    int minl = 0, maxl = N, mid;
    int cnt = 0;
    string ans = "1";
    string r;
    while(minl <= maxl) {
        mid = (minl + maxl)/2;
        int prev = 0;
        cnt = 1;
        ans = "1";
        F(1,K) {
            if (dt[i] - dt[prev] >= mid) {
                ans+="1";
                prev = i;
                cnt++;
                if (cnt == M) break;
            }
            else ans+="0";
        }
        while (ans.size() < K) ans += "0";

        if (cnt == M) {
            r = ans;
            minl = mid +1;
        }
        else maxl = mid -1;
    }
    cout << r;
    return 0;
}