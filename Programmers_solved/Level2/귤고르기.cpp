#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> num_data;
    for (int a : tangerine) {
        if (num_data.find(a) != num_data.end()) num_data[a]++;
        else num_data[a] = 1;
    }

    priority_queue<int,vector<int>, less<int>> pq;
    for (auto e : num_data) {
        pq.push(e.second);
    }

    while (!pq.empty()) {
        answer ++;
        k -= pq.top();
        pq.pop();
        if (k <= 0) break;
    }

    return answer;
}