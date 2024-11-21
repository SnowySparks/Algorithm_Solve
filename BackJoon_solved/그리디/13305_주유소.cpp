#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dist[100001]; //i-1 -> i 가는거리 i에 저장
int cash[100001]; //헤딩 위치
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    for (int i = 1; i<N; i++) {
        cin>>dist[i];
    }
    for (int i = 0; i<N; i++) {
        cin>>cash[i];
    } cash[N-1] = 0;
    long long answer = 0;
    
    int idx= 0, next = 0; long long distance=0;
    while (true) {
        distance =0;
        //해당자리 가격확인, 해당 주유소보다 더 싸고 바로 앞에 있는 곳
        while (cash[idx] <= cash[next]) {next++; distance+=dist[next];}
        answer+= cash[idx]*(distance);
        idx= next;
        if (idx >= N-1) break;
    }
    cout << answer;
    return 0;
}