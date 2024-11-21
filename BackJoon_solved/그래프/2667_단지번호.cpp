#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visited[26][26] = {false,};
string inp[26];
int cnt=0;
vector<int> v;

int dx[4] ={0,0,1,-1};
int dy[4] ={1,-1,0,0};

queue<pair<int,int>> q;

void bfs (int x , int y,int n) {
    q.push({x,y});
    visited[x][y]=true;
    cnt ++;
    int a,b,nx,ny;
    while (!q.empty()) {
        a=q.front().first;
        b=q.front().second;

        q.pop();

        for (int i=0;i<4;i++) {
            nx = a + dx[i];
            ny = b + dy[i];

            if (nx >=0 && ny>= 0 && nx <n && ny <n) {
                if (visited[nx][ny]== false && inp[nx][ny]== '1') {
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                    cnt++;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> inp[i];
    }

    for (int i=0;i<n;i++) { 
        for (int j=0;j<n;j++) {
            if (inp[i][j]=='1'&&visited[i][j]==false) {
                cnt = 0 ;
                bfs(i,j,n);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(),v.end());

    cout << v.size() << endl;
    for (auto e : v) {
        cout << e <<'\n';
    }

    return 0;
}