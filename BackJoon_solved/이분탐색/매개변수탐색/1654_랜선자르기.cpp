#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

long long dt[10001];

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k,n;
    cin >> k >> n ;
    
    long long left = 1 , right = -1 , mid, ans =0;
    for (int i=1; i<=k ; i++) {
        cin >> dt[i];
    }
    right = *max_element(dt+1,dt+1+k);

    int count= 0;

    while (left <= right) {
        count=0;
        mid = (left + right)/2;

        for (int i=1 ; i<=k ; i++) {
            count += (dt[i]/mid);
        }

        if (count < n) {
            right = mid -1;
        }
        else  {
            ans=mid;
            left = mid + 1;
        }
    }
    cout << ans;

}