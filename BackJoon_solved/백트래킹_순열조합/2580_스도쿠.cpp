#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sudo[9][9];
vector<pair<int, int> > loc; //0 위치

bool check (int r, int c) {
    //열 , 행
    for (int i = 0 ; i < 9 ; i++) {
        if (sudo[i][c] == sudo[r][c] && i!=r) return false;
        if (sudo[r][i] == sudo[r][c] && i!=c) return false;
    }
    //사각형
    for (int i = (r/3)*3 ; i < (r/3)*3+3; i++) {
        for (int j = (c/3)*3 ; j < (c/3)*3+3 ; j++) {
            if (sudo[i][j] == sudo[r][c] && (i != r || j != c)) return false;
        }
    }
    return true;
}

bool found = false; //플래그, 찾았을 경우, 남은 모든 dfs 함수 전부 강제종료용
void dfs(int x,const vector< pair< int, int> > &loc) {
    if (found == true ) return; //찾은 경우 강제 종료
    //전부 다 채웟을 경우
    if (x == loc.size()) {
        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j ++) {
                cout <<sudo[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
    }

//각각 0 자리에 값을 대입해서, 맞은 경우 게속 dfs 들어가기
    for (int i = 1 ; i < 10 ; i++) {
        sudo[loc[x].first][loc[x].second] = i;
        if (check(loc[x].first,loc[x].second)) dfs(x+1,loc);
        if (found) return;
    }
    //못 찾은 경우.
    sudo[loc[x].first][loc[x].second] = 0;
    return;
}

int main(void) {
    for (int i = 0 ; i < 9 ; i++) {
        for (int j = 0 ; j < 9 ; j++) {
            cin >> sudo[i][j];
            if (sudo[i][j] == 0) {
                loc.push_back({i,j}); 
            }
        }
    }
    cout << "--------------------------------------------------------"<<endl;
    dfs(0,loc);
    return 0;
}