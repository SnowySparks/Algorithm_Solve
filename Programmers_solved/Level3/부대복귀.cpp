#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector< vector <int> > maps(n+1);
    vector<int> dist(n+1);
    for (auto e : roads) {
        maps[e[0]].push_back(e[1]);
        maps[e[1]].push_back(e[0]);
    }
    
    fill(dist.begin(),dist.end(),0);
    queue<pair<int, int>> q; //위치, 거리
    
    int loc,d;
    q.push({destination,1});
    dist[destination] = 1;
    
    while (!q.empty()) {
        loc = q.front().first;
        d = q.front().second;
        q.pop();
        for (int e : maps[loc]) {
            if (dist[e] == 0) {
                q.push({e,d+1});
                dist[e]=d+1;
            }
        }
    }
    
    for (auto e : sources) {
        answer.push_back(dist[e] - 1);
    }
    

    return answer;
}