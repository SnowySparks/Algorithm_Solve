#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int n, int k, vector<int> enemy) {
    if (k >= enemy.size()) return enemy.size();
    int answer = 0;
    priority_queue<int,vector<int>,greater<> > pq;

    for (int i = 0 ; i < enemy.size() ; i++) {
        pq.push(enemy[i]);
        if (pq.size() > k) {
            n -= pq.top();
            pq.pop();
        }

        if (n < 0) return i;
    }
    return enemy.size();
}