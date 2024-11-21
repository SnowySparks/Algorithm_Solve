#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
bool visited[1000001][11];
int answer = -1;

void bfs(string inp,int len,int K) {
    queue<pair<string, int> > q;
    string outp; int idx = 0;
    q.push({inp,0});
    while (!q.empty()) {
        outp = q.front().first; idx=q.front().second;
        q.pop();
        if (idx == K) {
                answer = max(answer,stoi(outp));
            continue;
        }
        for (int i = 0 ; i < len-1 ; i++) {
            for (int j = i+1; j < len ; j++) {
                swap(outp[i],outp[j]);
                if (outp[0]!='0' && visited[stoi(outp)][idx+1]==false) {
                    q.push({outp,idx+1});
                    visited[stoi(outp)][idx+1] = true;
                }
                swap(outp[i],outp[j]);
            }
        }
    }
}
int main(void) {
    string inp; int K;
    cin >> inp >> K;
    int len = inp.size();
    bfs(inp,inp.size(),K);
    cout << answer; return 0;
}
