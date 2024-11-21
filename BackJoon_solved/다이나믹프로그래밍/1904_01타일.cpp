#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tile[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    tile[1]=1;
    tile[2]=2;
    tile[3]=3;
    
    for (int i=4;i<=N;i++) {
        tile[i]=(tile[i-2]+tile[i-1])%15746;
    }
    cout<< tile[N];


    return 0;
}