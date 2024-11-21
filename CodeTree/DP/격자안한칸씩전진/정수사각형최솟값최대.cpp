#include <iostream>
using namespace std;
const int inf = 1e9+7;
#define f(a, b, c) for(int a=b;a<c;++a)
int n;
int dp[101][101]; //dp[i][j] , (0, 0)에서 (i, j)까지 가는데 경로들의 최소값들중 최대값
int arr[101][101];

int mv[2][2] = {{1, 0}, {0, 1}};



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    f(i, 0, n) f(j, 0, n) cin >> arr[i][j];
    dp[0][0] = arr[0][0];
    f(i, 1, n) {
        dp[i][0] = min(dp[i-1][0], arr[i][0]);
        dp[0][i] = min(dp[0][i-1], arr[0][i]);
    }
    f(i, 1, n) f(j, 1, n) {
        dp[i][j] = min(max(dp[i-1][j], dp[i][j-1]), arr[i][j]);
    }

    // f(i,0,n) {
    //     f(j,0,n) cout << dp[i][j] <<' ';
    //     cout << '\n';
    // }
    cout << dp[n-1][n-1];
    return 0;
}


// #include <iostream>
// #include <algorithm>

// #define MAX_NUM 1000
// #define DIR_NUM 2
// #define UNUSED -1

// using namespace std;

// int n;
// int grid[MAX_NUM][MAX_NUM];
// int memo[MAX_NUM][MAX_NUM];

// bool InRange(int x, int y) {
//     return (0 <= x && x < n && 0 <= y && y < n);
// }

// void InitializeMemo() {
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             memo[i][j] = UNUSED;
// }

// int FindMaximin(int x, int y) {
//     // 미리 계산된 적이 있는 경우 해당 값을 사용해줍니다.
//     if(memo[x][y] != UNUSED)
//         return memo[x][y];

//     // 도착 지점에 도착하면 최솟값의 최대를 갱신해줍니다.
//     if( (x == n - 1) &&  (y == n - 1) )
//         return memo[n - 1][n - 1] = grid[n - 1][n - 1] ;

//     int dx[DIR_NUM] = {1, 0};
//     int dy[DIR_NUM] = {0, 1};

//     // 가능한 방향에 대해 탐색해줍니다.
//     int maximin = 0;
//     for(int i = 0; i < DIR_NUM; i++) {
//         int new_x = x + dx[i];
//         int new_y = y + dy[i];

//         if(InRange(new_x, new_y))
//             maximin = max(maximin,
//                           min(FindMaximin(new_x, new_y), grid[x][y]));
//     }

//     // 게산된 값을 memo 배열에 저장해줍니다.
//     memo[x][y] = maximin;

//     return maximin;
// }

// int main() {
//     cin >> n;

//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             cin >> grid[i][j];

//     InitializeMemo();

//     cout << FindMaximin(0, 0);

//     return 0;
// }