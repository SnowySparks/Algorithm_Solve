//https://school.programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define INF 200000000

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    priority_queue<pair<int,int>> pq;
    vector<vector<int>> table(n+1);
    
    
    for (auto e : edge) {
        table[e[0]].push_back(e[1]);
        table[e[1]].push_back(e[0]);
    }
    
    vector<int> dist(n+1);
    fill (dist.begin(), dist.end(),INF);
    dist[1]=0;
    pq.push(make_pair(0,1));

    //
        while (!pq.empty()) {
        int cost = -pq.top().first;
        int loc = pq.top().second;
        pq.pop();
        if (dist[loc]<cost) {
            continue;
        }
        for (int i=0; i<table[loc].size();i++) {
            int next_dist = cost + 1;
            if (dist[table[loc][i]]>next_dist) {
                dist[table[loc][i]]=next_dist;
                pq.push(make_pair(-next_dist,table[loc][i]));
            }         
        }
    }
    return count(dist.begin()+1,dist.end(),*max_element(dist.begin()+1,dist.end()));
}