#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const double tr = sqrt(2);
int ans = 0;
vector<double> arr(8);
vector<pair<double ,double> > dp(8);
vector<bool> v(8,false);
vector<double> dt;
double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
} // (12) x (13)
double ccw(pair<double, double> a1,pair<double, double> a2,pair<double, double> a3) {
    return ccw(a1.first,a1.second,a2.first,a2.second,a3.first,a3.second);
}

void cal(void) {
    dp[0] = {0.0,dt[0]};
    dp[1] = {dt[1]/tr,dt[1]/tr};
    dp[2] = {dt[2],0.0};
    dp[3] = {dt[3]/tr,-dt[3]/tr};
    dp[4] = {0.0,-dt[4]};
    dp[5] = {-dt[5]/tr,-dt[5]/tr};
    dp[6] = {-dt[6],0.0};
    dp[7] = {-dt[7]/tr,dt[7]/tr};
}

//back tracking

void back_track(void) {
    if (dt.size() == 8) {
        cal();
        for (int i = 0 ; i < 8; i++) {
            if (ccw(dp[i],dp[(i+1)%8],dp[(i+2)%8]) > 0) return; 
        }
        ans++;
        return;
    }

    for (int i = 0 ; i < 8 ; i++) {
        if (!v[i]) {
            v[i] = true;
            dt.push_back(arr[i]);
            back_track();
            dt.pop_back();
            v[i]=false;
        }
    }
    
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0 ; i < 8; i ++) cin >> arr[i];
    back_track();
    cout << ans;
    return 0;
}