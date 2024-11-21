#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lst[110]; //순서
int lastappear[101];
vector<int> plug; // 꼽혀있는 개수

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N=4, K;
    vector<int> dt;
    cin >> K;
    for (int i = 1 ; i <= K ; i++) {
        cin >> lst[i];
        lastappear[lst[i]] = i; //해당 번호가 가장 마지막에 뜨는위치
    }
    int answer = 0;
    for (int i = 1 ; i <= K ; i++) {
        if (plug.size() == 0) {plug.push_back(lst[i]); answer++;} //비어있음
        else if ( find(plug.begin(), plug.end(),lst[i]) != plug.end()) continue; //이미 꼽힘
        else if ( plug.size() < N) {plug.push_back(lst[i]); answer++; }// 빈자리
        else {
            int boxloc = -1; //대상 박스 교체,
            int lastlstidx = -1; // 박스의 가장 뒤의 처음으로 뜨는 위치
            int temp = 0;
            for (int k = 0 ; k < 4 ; k++) {
                temp = 0;
                if ( lastappear[plug[k]] < i) {
                    temp = (i-lastappear[plug[k]]) * 10000;
                }
                else {
                    for (int p = i+1; p <= K ; p++) {
                        if (lst[p] == plug[k]) {
                            temp = p;
                            break;
                        }
                    }
                }
            if (lastlstidx < temp) {
                boxloc = k;
                lastlstidx = temp;
                }                
            }
            plug[boxloc] = lst[i];
            answer++;
        }
    }
    cout << answer; return 0;
}