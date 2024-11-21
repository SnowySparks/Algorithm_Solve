#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<pair<string, int> > ans; //상태저장
    string cmd, val; int time;
    for (int i = 0 ; i < N ; i++) {
        cin >> cmd >> val >> time;

        if (cmd == "type") {
            if (ans.empty()) ans.push_back({val,time});
            else {
                ans.push_back({ ans.back().first+val,time});
            }
        }
        else {
            int loc = ans.size() -1;
            int findtime = time - stoi(val);
            for (;loc>= 0 ; loc--) {
                if (ans[loc].second < findtime ) break; 
            }
            if (loc >= 0) ans.push_back({ans[loc].first,time});
            else ans.push_back({"",time});
        }
    }

    cout << ans.back().first; return 0;

}