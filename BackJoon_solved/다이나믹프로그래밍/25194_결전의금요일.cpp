#include <iostream>
#include <vector>
using namespace std;

vector<int> li;
int day[1000];
bool dfs_check = false;

void dfs(int sum, int loc) {
    if (loc == li.size()) {
        
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    for(int i = 0 ; i< N ;i ++) cin >> day[i];
    bool check = false;
    for(int i = 0 ; i< N ; i++) {
        day[i] %= 7;
        if (day[i]==4) {cout <<"YES"; return 0;}
        else if (day[i]) {li.push_back(day[i]);}

        if (li.size() > 6) {cout <<"YES"; return 0;}
    }



    return 0;
}