#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tb;

int main(void) {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int answer = 0;
    int N, C;
    cin >> N >> C ;
    int mini, maxi, temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        tb.push_back(temp);
    }
    sort(tb.begin(), tb.end());

    mini = 1; maxi = tb[ N- 1 ] - tb[0]; //최소간격, 최대간격

    int mid, ins_count,start,end;

    //최소 간격을 찾는 것,
    //최소 간격을 기준으로 공유기 간 거리가 mid 보다 클 때 설치하도록 시물레이션
    while (mini <= maxi) {
        mid = (mini + maxi)/2;
        ins_count = 1;
        start = tb[0];
        for (int i = 1 ; i < N ; i++) {
            end = tb[i];
            if (end - start >= mid) {
                ins_count++;
                start = end;
            }
        }
        if (ins_count >= C) {
            answer = mid;
            mini = mid +1;
        }
        else { maxi = mid - 1;}
    }
    cout << answer;
    return 0;
}