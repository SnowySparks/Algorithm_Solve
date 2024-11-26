#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

vector<int> adj[26]; // 인접 그래프
int cost[26]; // cost
int indegree[26]; 
int dp[26]; // 해당 작업이 처리되는 가장 최소 시간
vector<string> res;

// c++ 전용 문자열 분리함수
void split(string input, char delimiter) {
    res.clear();
    istringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        // cout << "temp : " << temp << '\n';
        res.push_back(temp); 
    }
}

int main(void) {
    // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string inp;
    int max_node = 0;
    // 입력
    while (getline(cin, inp))
    {      
        ++max_node;
        split(inp,' ');
        int node = res[0][0] - 'A';
        cost[node] = stoi(res[1]);
        if (res.size() == 3) {
            indegree[node] = res[2].size();
            for (char ch : res[2]) {
                adj[ch-'A'].push_back(node);
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (indegree[i] == 0 && cost[i] > 0) {
            q.push(i);
            dp[i] = cost[i];
        }
    }

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        for (int child : adj[node]) {
            indegree[child]--;
            dp[child] = max(dp[node] + cost[child], dp[child]);
            if (indegree[child] == 0) q.push(child);
        }
    }

    cout << *max_element(dp, dp+26);
    
    return 0;
}