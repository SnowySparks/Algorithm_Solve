#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int maps[100][100][100];
bool visited[100][100][100];
bool check=true;
int n,d_x,d_y;
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

queue<tuple<int,int,int>> q;
queue<tuple<int,int,int>> p;
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int cot=0;
    int mx,my,mz,nx,ny,nz;
    bool check=true;
    cin >> my >> mx >> mz;


    int e[3];


for (int k = 0 ; k< mz ; k++) {
    for (int i = 0 ; i <mx;i++) {
        for (int j = 0 ; j < my ; j++) { 
            cin >> maps[k][i][j];
            if (maps[k][i][j] == 1) {
                q.push(make_tuple(k,i,j));
                visited[k][i][j] = true;
            }
        }
    }
}
    while (!(q.empty() && p.empty())) {
        if (p.empty()) {
            cot++;
            while (!q.empty()) {
            e[0] = get<0>(q.front());
            e[1] = get<1>(q.front());
            e[2] = get<2>(q.front());
            q.pop();
            for (int i=0;i<6;i++) {
                nx = e[1] + dx[i];
                ny = e[2] + dy[i];
                nz = e[0] + dz[i];

                if (nz >= 0 && nx >= 0 && ny >= 0 &&nz < mz&&nx < mx && ny < my) {
                    if ( (!visited[nz][nx][ny]) && maps[nz][nx][ny]==0) {
                        visited[nz][nx][ny] = true;
                        maps[nz][nx][ny] =1;
                        p.push(make_tuple(nz,nx,ny));
                    }
                }
            }
            }
        }
        else if (q.empty()) {
            cot++;
            while (!p.empty()) {
            e[0] = get<0>(p.front());
            e[1] = get<1>(p.front());
            e[2] = get<2>(p.front());
            p.pop();
            for (int i=0;i<6;i++) {
                nx = e[1] + dx[i];
                ny = e[2] + dy[i];
                nz = e[0] + dz[i];

                if (nx >= 0 && ny >= 0 &&  nz >= 0&& nx < mx && ny < my && nz < mz) {
                    if ( (!visited[nz][nx][ny]) && maps[nz][nx][ny]==0) {
                        visited[nz][nx][ny] = true;
                        maps[nz][nx][ny] =1;
                        q.push(make_tuple(nz,nx,ny));
                    }
                }
            }
        }
        }
    }
    for (int k = 0; k < mz; k++) {
        for (int i = 0 ; i < mx; i++) { 
            for (int j = 0 ; j < my; j++) {
                if (maps[k][i][j]==0) {
                    check=false;
                }
            }
            if (!check) break;
        }
        if (!check) break;
    }


    cout << (check ? cot -1 : -1 ) <<endl;
    return 0;
}