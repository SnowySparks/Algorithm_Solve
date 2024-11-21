#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define f(a,b,c) for (int a=b;a<c;a++)
using namespace std;

bool isprime[10000];
int v[10000];

int chage_val(int val, int n, int num) {
    int p;
    if (n == 3) p=1000;
    else if (n == 2) p=100;
    else if (n == 1) p= 10;
    else p = 1;

    int left = val / (p*10) * (p*10) + val % p;
    return left + num*p;
}

void bfs(int start) {
    fill(v+1000,v+10000,-1);
    v[start] = 0;
    queue<int> q; q.push(start);
    
    while (!q.empty()) {
        int loc = q.front(); q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            for (int j = 0; j <= 9 ; j ++) {
                if (i == 3 && j==0) continue;
                int nxt = chage_val(loc,i,j);
                if (v[nxt] == -1 && isprime[nxt]) {
                    q.push(nxt);
                    v[nxt]= v[loc]+1;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(isprime,true,sizeof(isprime));
    isprime[0] = false; isprime[1] = false;
    for (int i =2 ; i <10000; i++) {
        if (isprime[i]) {
           for (int j=  i*i; j<10000 ; j+=i) isprime[j]=false;
        }
        else continue;
    }

    int t; cin >> t;
    while(t--) {
        int a,b; cin >> a >> b;
        if (a==b) {cout << "0\n"; continue;}
        bfs(a);
        if (v[b]==-1) cout <<"impossible\n";
        else cout << v[b] <<'\n';
    }
    return 0;


}
