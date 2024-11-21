#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    int n,m; cin >> n >> m;
    long long left = 1, right = 1000000000;
    vector<int> lgs(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> lgs[i];
    }
    
    long long mid=0;
    long long temp=0;
    long long ans = 0;
    while (left <= right) {
        mid=(left + right)/2;
        temp = 0;
        for (auto e : lgs) {
            temp+= ( e > mid ? e-mid : 0); 
        }
        if (temp >= m) {
             ans = mid;
            left = mid +1;
        }
        else {
            right = mid-1;
        }
    }
    cout << ans;
    return 0;

 
}