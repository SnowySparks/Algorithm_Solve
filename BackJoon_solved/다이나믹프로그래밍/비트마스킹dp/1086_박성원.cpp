#include <iostream>
#include <string>
#include <cstring>
#define f(a,b,c) for (int a = b; a < c; a++)
using namespace std;

int N, K;
string inp[15]; //입력
int ar[15], len[15] ,d[56];
long long dp[100][1<<15];
long long ft[16] = {1, 1, };

int to_num(const string &a) {
    int r = 0;
    for(auto e : a) {
        r*=10; r%=K; r+=(e - '0'); r%=K;
    }
    return r; }

long long dfs(int remind, int state) {
    if (state == (1<<N)-1) return (remind == 0) ? 1 : 0;
    long long &ret = dp[remind][state];
    if (ret != -1) return ret;
    ret = 0;
    f(i,0,N) {
        if (!(state&(1<<i))) {
            int t = remind * d[len[i]] + ar[i];
            t%=K;
            ret+=dfs(t,state|(1<<i));
        }
    }
    return ret; }

long long gcd(long long a, long long b) {
    long long r;
    while(b) {
        r = a%b; a = b; b= r; } 
    return a; }

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    f(i,2,16) ft[i] = ft[i-1]*i;
    cin >> N;
    f(i,0,N) cin >> inp[i];
    cin >> K;
    d[0] = 1%K;
    f(i, 0, N) {
        len[i] = inp[i].size();
        ar[i] = to_num(inp[i]); }
    f(i,1,56) d[i] = d[i-1]*10%K;
    memset(dp, -1, sizeof(dp));
    long long ans =dfs(0,0);
    if (ans == 0) {cout << "0/1";}
    else {
        long long g = gcd(ans, ft[N]);
        cout << ans/g <<"/" << ft[N]/g;
    }
    return 0;
}