#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct comp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first; }
};
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    map<string, int> datas;
    int N ; cin >> N;
    string inp1;
    while (N--) {
        cin >> inp1;
        if (datas.find(inp1) == datas.end()) datas.insert({inp1, 1});
        else datas[inp1]++;
    }
    priority_queue<pair<int,string>, vector< pair<int,string> >, comp > q;
    for (auto a : datas) {
        q.push({a.second, a.first}); }
    
    cout << q.top().second << '\n';
    return 0;
}