#include <iostream>
#include <string>

#define MAX_N 10

using namespace std;

int n;
string arr[MAX_N];

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // 뒤에서부터 선택을 진행합니다.
    // 현재 위치에서 꼭 눌러야만
    // 문제 조건을 만족시킬 수 있다면
    // 눌러주고 넘어갑니다.
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--)
        for(int j = n - 1; j >= 0; j--) {
            // arr[i][j]가 1이면 누릅니다.
            if(arr[i][j] == '1') {
                cnt++;
                for(int k = 0; k <= i; k++)
                    for(int l = 0; l <= j; l++)
                        arr[k][l] = '0' + '1' - arr[k][l];
            }
        }

    cout << cnt;
    
    return 0;
}