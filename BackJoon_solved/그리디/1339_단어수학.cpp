#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string dt[10];
unordered_map<char, int> nm;
bool comp(const pair<char, int> &p1, const pair<char, int> &p2) {
    return p1.second > p2.second;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> dt[i];
    int lv;
    for (auto e : dt) {
        lv = 1;
        for (int k = e.size() -1; k >= 0; k--) {
            nm[e[k]]+=lv;
            lv*=10;
        }
    }
    vector<pair<char ,int> > np;
    for (auto e : nm) np.push_back(e);
    sort(np.begin(), np.end(), comp);
    long long ans = 0;
    int num = 9;
    for (auto e : np) {
        ans += (num * e.second);
        num--;
    }
    cout <<ans;

}