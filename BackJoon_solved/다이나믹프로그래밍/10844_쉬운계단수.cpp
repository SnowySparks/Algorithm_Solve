#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000

long long table[101][10];

int main(void) {
    int b;
    cin >> b;
    for (int i=1;i<=9;i++) {
        table[1][i]=1;
    }

    for (int k=2;k<=b;k++) {
        table[k][0]=table[k-1][1];
        table[k][9]=table[k-1][8];
        for (int p=1;p<=8;p++) { 
            table[k][p]=(table[k-1][p-1]+table[k-1][p+1])%INF;
        }
    }
    long long ans=0;
    for (int i=0;i<=9;i++) {
        ans+=table[b][i];
    }
    cout<<ans%INF<<endl;

    return 0;

}