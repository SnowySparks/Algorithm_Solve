#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int podo[10001];
int dp[10001];

int main(void) {
   int a;
   cin>>a;

   for (int i=1;i<=a;i++) {
      cin>>podo[i];
   }

   dp[1]=podo[1];
   dp[2]=podo[1]+podo[2];

   for (int i=3;i<=a;i++) {
      dp[i]=max(dp[i-1],max(podo[i-1]+podo[i],max(dp[i-3]+podo[i]+podo[i-1],dp[i-2]+podo[i])));
   }
   cout<<dp[a]<<endl;
   return 0;  
}

