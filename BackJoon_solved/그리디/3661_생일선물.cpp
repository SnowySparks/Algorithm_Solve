#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T, n, p;// 테스트 케이스, 인원수, 선물가격 총량
int pay_per_p, total; // 1인당 내야하는 양 (내림처리), 1인당 낼수있는 양의 총합   
struct info {
    int a; // 최대 낼 수 있는 양 
    int idx; // 인덱스값
    int pay;
    info() {
        a = 0; // 감당 가능양
        idx = 0; // 인덱스값
        pay = 0; // 지불양
    };
};

info arr[100];

int main(void) {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (int test = 0; test < T; ++test) { // 테스트 케이스
        cin >> p >> n;
        pay_per_p = p / n;
        total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].a;
            arr[i].pay = 0;
            arr[i].idx = i;
            total += arr[i].a;
        }

        // 각 인원이 감당 가능한 비용 총합 < 선물가격
        if (total < p) {
            cout <<"IMPOSSIBLE\n";
            continue;
        }

        // 먼저 각 인원마다 낼 수 있는 최대치를 전부 지불
        for (int i = 0; i < n; ++i) {
            int payable = min(pay_per_p, arr[i].a);
            p -= payable;
            arr[i].pay = payable;
        }

        sort(arr, arr+n, [](info &a, info &b) {
                // 먼저 지불 가능양이 큰 녀석 위주, 동일할 경우 인덱스 오름차순
            if (a.a != b.a) return a.a > b.a; 
            return a.idx < b.idx;
        } );

        // 가용 가능한 사람 카운팅
        int able_people_count = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i].a > arr[i].pay) ++able_people_count;
        }

        // 그다음 남은 pay가 있을 경우, 가능한 최대한 낼 수 있는 사람들 한헤서 분배
        while (p > 0 && able_people_count > 0)
        {
            int ppp = p / able_people_count;
            // 만약에 아직 내야하는 값이 있지만, n빵이 불가능한 경우
            // -> 가용 인원수 자체를 줄이기
            if (ppp == 0) {
                able_people_count--;
                continue;
            }
            int nxt_able_cnt = able_people_count;
            for (int i = 0; i < able_people_count; ++i) {
                int payable = min(arr[i].a - arr[i].pay, ppp);
                arr[i].pay += payable;
                p -= payable;
                if (arr[i].a == arr[i].pay) nxt_able_cnt--;
            }
            able_people_count = nxt_able_cnt;
        }

        if (p > 0) {
            cout <<"IMPOSSIBLE\n";
            continue;
        }

        sort(arr, arr+n, [](info &a, info &b) {
            return a.idx < b.idx;
        });

        for (int i = 0; i < n; ++i) {
            cout << arr[i].pay << ' ';
        }
        cout << '\n';
    }

    return 0;
}

// 풀이법
//계속해서 min(낼 수 있는 최대 양, 남아있는 선물비용/지불 가능한 사람 수) 를 계속해서 루프 돌면서 최대한 균형 맞추기. 
//다만 처음엔 min(낼 수 있는 최대 양, p/n)