#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct _info {
    int x, y, p;
} info; // 각 가정집 정보

pair<int, int> jumpo[20]; //모든 점포 데이터
vector<pair<int, int> > lst; // 모든 점포 중 백트래킹으로 골라 넣은 것

int N; //가구의 수
double R; // 배달 최대 거리 값
info house[100]; //가구데이터
bool visited[100]; //
int answer = 0; //답

double dist(int x1, int y1, int x2, int y2) {
    return sqrt( pow( abs(x1 - x2), 2) + pow( abs(y1 - y2), 2)); }

void check(void) {
    memset(visited, false, sizeof(visited));
    double d;
    for (int i =  0 ; i < N ; i++) {
        for (auto e : lst) {
            d = dist(e.first, e.second, house[i].x, house[i].y);
            if (d <= R) {visited[i] = true; break;}
        }
    }
    int pcnt = 0;
    for (int i = 0; i < N ; i++) {
        if (visited[i]) pcnt+=house[i].p;
    }
    answer = max(answer, pcnt);
}

void backtrack(int cnt, int idx, int Np, int Mp) {
    if (cnt == Mp) {
        check();
        return;
    }
    for (int i = idx; i < Np ; i++) {
        lst.push_back(jumpo[i]);
        backtrack(cnt+1, i+1, Np, Mp);
        lst.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int K; cin >> K >> R; // K :피잣집 총 개수
    int M; cin >> M; // 모든 점포 개수
    for (int i = 0 ; i < M ; i++) {
        cin >> jumpo[i].first >> jumpo[i].second;
    }
    cin >> N; //모든 집 정보
    
    for (int i = 0; i < N ; i++) {
        cin >> house[i].x >> house[i].y >> house[i].p;
    }

    backtrack(0,0,M,K);
    cout << answer; return 0;

}