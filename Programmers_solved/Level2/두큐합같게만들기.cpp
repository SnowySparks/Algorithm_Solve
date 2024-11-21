#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long ans1 = 0, ans2 = 0;
    int answer = 0;
    int size = queue1.size() + queue2.size();
    size *= 2;
    
    queue<int> q1, q2;
    
    for (int e : queue1) {
        ans1 += e;
        q1.push(e);
    }
    for (int e : queue2) {
        ans2 += e;
        q2.push(e);
    }
    
    if (queue1.size() == 1 && queue2.size() == 1) {
        return (ans1 == ans2 ? 0 : -1);
    }
    
    while (ans1 != ans2 && answer < size ) {
        if (ans1 > ans2) {
            q2.push(q1.front());
            ans2+= q1.front();
            ans1-= q1.front();
            q1.pop(); answer++;
        }
        else if (ans1 < ans2) {
            q1.push(q2.front());
            ans1+=q2.front();
            ans2-=q2.front();
            q2.pop(); answer++;
        }
    }
    return (answer >= size ? -1 : answer);
}