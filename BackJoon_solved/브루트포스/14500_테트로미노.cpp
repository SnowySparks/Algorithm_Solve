#include <iostream>
#include <vector>
#define f(a,b,c) for(int a= b; a<c;++a)
using namespace std;

int n, m arr[500][500];



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f(i,0,n) f(j,0,m) cin >> arr[i][j];
}