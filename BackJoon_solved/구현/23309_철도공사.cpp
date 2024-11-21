#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

pair<int,int> stations[1000001]; //이전역, 이후역로 설정. -1 : 없음을 의미.


void bn(int loc, int make) { //loc 다음 역을 make 역이라는 것을 만듬dndkdk
    cout << stations[loc].second<<'\n';
    int origin_loc_next = stations[loc].second;
    stations[loc].second = make;
    stations[make] = {loc,origin_loc_next};
    stations[origin_loc_next].first = make;

}

void bp(int loc, int make) { //loc 이전 역을 make 역이라는 것을 만듬
    cout << stations[loc].first<<'\n';
    int origin_loc_before = stations[loc].first;
    stations[loc].first = make;
    stations[make] = {origin_loc_before,loc};
    stations[origin_loc_before].second = make;

}

void cn(int loc) { //현재 역의 다음 역을 폐쇠함, 단 설립 역이 2개 이상이어야 한다.

    cout << stations[loc].second << '\n';
    int origin_loc_after = stations[loc].second;

    stations[stations[origin_loc_after].second].first = loc;
    stations[loc].second = stations[origin_loc_after].second;

}

void cp(int loc) {//현재 역의 이전 역을 폐쇠함

    cout << stations[loc].first << '\n';
    int origin_loc_before = stations[loc].first;

    stations[stations[origin_loc_before].first].second = loc;
    stations[loc].first = stations[origin_loc_before].first;

}

int main(void) {

    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int N,M,temp,before,first;
    cin >> N >> M;

    //원형 linked list 구현 with index.
    // 탐색을 O(1)로 만들기 위함.

    
    for (int i = 1 ; i <= N ; i++) {
        cin >> temp;
        if ( i == 1 ) {
            stations[temp] = {-1,-1};
            before = temp;
            first = temp;
        }
        else if (i == N) {
            stations[before].second = temp;
            stations[temp] = {before,first };
            stations[first].first = temp;
        }
        else {
            stations[before].second = temp;
            stations[temp]  = {before,-1};
            before = temp;
        }
    }

    string input;
    int loc , a;

    while (M--) {
        cin >> input;
        if (input == "BN") {
            cin >> loc >> a;
            bn(loc,a);
        }
        else if (input=="BP") {
            cin >> loc >> a;
            bp(loc,a);
        }
        else if (input=="CP") {
            cin >> loc;
            cp(loc);
        }
        else {
            cin >> loc;
            cn(loc);
        }
    }
    return 0;
}