#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define inf 100001
using namespace std;

int visited[inf];
int N;
vector<pair<int, int> > gh[inf];

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}


//지름구하기
pair<int, int> find_longest(int start, int cost) {
    memset(visited, -1, sizeof(visited));
    queue<int> q;
    visited[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int loc = q.front();
        q.pop();

        for (auto e : gh[loc]) {
            if (visited[e.first] != -1) continue;
            q.push(e.first);
            visited[e.first] = visited[loc] + e.second;
        }
    }

    int *location = max_element(visited+1, visited+1+N);
    return {location - visited, *location};
}

int main(void) {
    cin >> N;
    int a, b, cost;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >> cost;
        gh[a].push_back({b,cost});
        gh[b].push_back({a,cost});
    }
    // 트리지름
    pair<int, int> fst = find_longest(1,0);
    pair<int, int> sec = find_longest(fst.first,0);
    //fst.first - sec.first 가 트리 지름이 됨

    pair<int, int> first_find = find_longest(fst.first,0);
    vector<pair<int, int> > dts1;
    for (int i = 1 ; i <= N; i++) {
        if (i!=first_find.first) {
            dts1.push_back({i,visited[i]});
        }
    }
    pair<int, int> second_find = find_longest(sec.first,0);
    vector<pair<int, int> > dts2;
    for (int i = 1 ; i <= N; i++) {
        if (i!=second_find.first) {
            dts2.push_back({i,visited[i]});
        }
    }
    //
    sort(dts1.begin(), dts1.end(), comp);
    sort(dts2.begin(), dts2.end(), comp);
    cout <<( (dts1[0].second < dts2[0].second) ? dts2[0].second : dts1[0].second );
    return 0;
}
