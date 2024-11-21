#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>

#define MAX_N 100000
#define MAX_S 500000

using namespace std;

// 변수 선언
int n;
char s_arr[MAX_S];
// (개수, )개수를 쌍으로 하여 관리합니다.
pair<int, int> brackets[MAX_N];

long long ans;

// (b1, b2), (b2, b1) 중
// 점수를 더 많이 얻을 수 있는 경우로 정렬합니다.
bool cmp(pair<int, int> b1, pair<int, int> b2) {
    int open1, closed1;
    tie(open1, closed1) = b1;
    int open2, closed2;
    tie(open2, closed2) = b2;
    return (long long) open1 * closed2 > (long long) open2 * closed1;
}

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s_arr;
        string s = s_arr;
        int open = 0, closed = 0; // 열린 소괄호, 닫힌 소괄호 수를 셉니다.
        for(int j = 0; j < (int) s.size(); j++) {
            if(s[j] == '(')
                open++;
            else {
                closed++;

                // 해당 문자열 만으로 얻게 되는 점수는
                // 미리 답에 더해줍니다.
                ans += open;
            }
        }
        brackets[i] = make_pair(open, closed);
    }

    sort(brackets, brackets + n, cmp);

    // 정렬된 순서대로 보며
    // 각 문자열을 붙였을 때
    // 새롭게 얻게되는 점수를 더해줍니다.
    int open_sum = 0;
    for(int i = 0; i < n; i++) {
        int open, closed;
        tie(open, closed) = brackets[i];
        // 답을 갱신해줍니다.
        ans += (long long) open_sum * closed;

        // open_sum을 누적해줍니다.
        open_sum += open;
    }

    cout << ans;
    return 0;
}