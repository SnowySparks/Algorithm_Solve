#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool comp(const pair<long long ,int>& a, const pair<long long ,int>& b) {
    if (a.second == b.second) return a.first <b.first;
    return a.second > b.second;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    long long inp;
    unordered_map<long long, int> dt;
    while(N--) {
        cin >> inp;
        dt[inp]++;
    }
    vector<pair<long long, int> > tb;
    for (auto e : dt) {
        tb.push_back({e.first, e.second});
    }
    sort(tb.begin(), tb.end(),comp);
    cout << tb[0].first ;
    return 0;
}