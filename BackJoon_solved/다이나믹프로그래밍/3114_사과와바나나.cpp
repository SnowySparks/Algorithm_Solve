#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int R, C;
#define f(a, b, c) for(int a=b; a<c;++a)

// a, b에 대한 누적합 연산 (행 방향만)
int a[1501][1501];
int b[1501][1501];

int dp[1501][1501]; //dp[r][c] -> (1, 1) 에서 불도저가 (r, c)로 이동할 때 가치 최대값

int ans = -1;
const int INF = 1e9 + 7;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // input
    string tmp;
    cin >> R >> C;
    f(r, 1 ,R+1) {
        f(c, 1, C+1) {
            cin >> tmp;
            int val = stoi(tmp.substr(1, tmp.size()-1));

            switch (tmp[0])
            {
            case 'A':
                a[r][c] += val;
                break;
            case 'B':
                b[r][c] += val;
                break;
            }
        }
    }
    // 과수원a, b 입력 및 누적합
    f(c, 1, C+1) {
        f(r, 1, R+1) {
            a[r][c] += a[r-1][c];
            b[r][c] += b[r-1][c];
        }
    }
    // 전처리
    f(r, 1, R+1) dp[r][1] = a[R][1] - a[r][1]; //(1,1) ->(R,1)로 밀어버리는 경우
    f(c, 2, C+1) dp[1][c] = dp[1][c-1] + a[R][c] - a[1][c]; // (1,1) -> (1, C)로 밀어버리는 경우

    // dp식
    f(r, 2, R+1) {
        f(c, 2, C+1) {
            dp[r][c] = dp[r-1][c] - (a[r][c] - a[r-1][c]); //한칸 아래로 가는 경우
            dp[r][c] = max(dp[r][c], dp[r][c-1] + a[R][c] - a[r][c] + b[r-1][c]); // 우측으로 이동
            dp[r][c] = max(dp[r][c], dp[r-1][c-1]+ a[R][c] - a[r][c] + b[r-1][c]); // 우측 하단으로 이동
        }
    }
    cout <<dp[R][C];
    return 0;
}