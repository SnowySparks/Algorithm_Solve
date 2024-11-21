#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

#define INF 200000000

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    //동적할당
    int **graph = new int*[N];
    for (int i=0;i<N;i++) {
        graph[i]=new int[N];
        fill(graph[i],graph[i]+N,INF);
    }
    //그래프대입
    for (auto e : road) {

        if (graph[e[0]-1][e[1]-1] > e[2]) {
        graph[e[0]-1][e[1]-1]=e[2];
        graph[e[1]-1][e[0]-1]=e[2]; }
    }
    

    //다익스트라 알고리즘
    int *length=new int[N];
    fill (length,length+N,INF);
    length[0]=0;
    priority_queue<pair<int,int>> pq;//(비용,도착노드)
    pq.push(make_pair(0,0));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int loc = pq.top().second;

        pq.pop();

        if (length[loc]<cost) {
            continue;
        }

        for (int i=0; i<N;i++) {
            int next_dist = cost + graph[loc][i];
            if (length[i]>next_dist) {
                length[i]=next_dist;
                pq.push(make_pair(-next_dist,i));
            }
        }
    }

    for (int i=0;i<N;i++) {
        if (length[i]<=K) {
            answer++;
        }
    }
//동적할당해제
    delete[] length;
    for (int i=0;i<N;i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return answer;
}