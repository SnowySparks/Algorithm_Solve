#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

void cal(const vector<int> & b, vector<int> &an) {
    double lean_crit, cal_lean = 0.0;
    for (int i = 0 ; i <n;i++) {
        lean_crit = -1e11;
        for (int k = i+1; k < n; k++) {
            cal_lean = (b[k] - b[i])*1.0/ (k-i);
            if (lean_crit >= cal_lean) continue;;
            lean_crit = cal_lean;
            an[i]++; an[k]++;
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; 
    vector<int> bd(n);
    vector<int> ans(n,0);
    for (int i = 0 ; i < n ; i ++) cin >> bd[i];
    cal(bd,ans);
    cout << *max_element(ans.begin(),ans.end());

    return 0;
}