#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int d (int input) {
    return (2*input) % 10000;
}
int s (int input) {
    return (input + 9999) % 10000;
}
int r (int input) {
    return (input / 10) + (input % 10) * 1000;
}
int l (int input) {
    return (input % 1000) * 10 + (input / 1000);
}
bool visited[10001] = {false,};

void bfs (int start, int end) {
    queue<pair<int,string>> q;
    q.push({start,""});
    int tp; string temp;
    int D, S, L, R;
    visited[start] = true;
    while (!q.empty()) {
        tp = q.front().first;
        temp = q.front().second;
        q.pop();
        if (tp == end) {
            cout << temp <<'\n';
            return;
        }
        D = d(tp); S = s(tp); L = l(tp); R = r(tp);
        if (!visited[D]) {
            visited[D] = true;
            q.push({D,temp+"D"});
        }
        if (!visited[S]) {
            visited[S] = true;
            q.push({S,temp+"S"});
        }
        if (!visited[L]) {
            visited[L] = true;
            q.push({L,temp+"L"});
        }
        if (!visited[R]) {
            visited[R] = true;
            q.push({R,temp+"R"});
        }
    }
}

int main(void) {
    int N ; cin >> N;
    int a ,b;
    while (N--) {
        cin >> a >> b;
        bfs(a,b);
        fill (visited , visited+10001, false);
    }
    return 0;
}