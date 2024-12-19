#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std; 
int n, k;
int arr[300];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int l = -1, r = 0; // 이분탐색 : l 은 arr 입력값중 최대값, r은 전체 총합
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        l = max(l, arr[i]);
        r+=arr[i];
    }

    // 극값 조건 1 : n = 1 -> 예외처리 (출력값은 1, n) 끝
    if (n == 1) {
        cout << arr[0] <<'\n' << 1;
        return 0;
    }

    // 극값 조건 2 :  n == k -> 예외처리 ( 전부 1씩 출력)
    if  (n == k) {
        cout << l <<'\n';
        for (int i = 0; i < n; ++i) {
            cout << 1 <<' ';
        }
        return 0;
    }

    int sum = 0, groupCount = 0;
    int midPoint = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        groupCount = 1; sum = arr[0];
        for (int i = 1; i < n; ++i) {
            sum+= arr[i];
            if (sum > mid) {
                sum = arr[i];
                ++groupCount;
            }
        }

        if (groupCount > k) {
            l = mid + 1;
        }
        else {
            midPoint = mid;
            r = mid - 1;
        }
    }
    cout << midPoint <<'\n';
    sum = arr[0]; groupCount = 1; int cnt = 1;

    int i = 1;
    for (; i < n; ++i) {

        // 해당 계산은 일단 i는 그룹핑 계속 된다는 가정
        sum += arr[i];
        ++cnt;

        if (sum > midPoint) {
            cout << cnt - 1 <<' ';
            cnt = 1;
            sum = arr[i];
            ++groupCount;
            if ( k - groupCount == n - i - 1) {
                break;
            }
        }
        else if (i == n-1 && cnt != 0) {
            cout << cnt;
        }
    }
    for (; i < n; ++i) {
        cout << 1 <<' ';  
    }
    return 0;
}

// 풀이방법 
// 먼저 최대값의 한계선에 대해서 매개 변수 탐색을 통해서 구한다
// 이때 그리디 적 생각으로 최대값의 한계선을 정하고, 구간을 나눈다고 할 때 k개 이하인 경우는 만족
// 왜냐하면 k개보다 작더라고 그룹을 임의로 나눌 수 있다는 뜻이니까

// 한계값이 정하면 이제 맞게 출력을 해야 하는데
// k - groupCount == n - i - 1 라는 조건식이 부합한다는 것은 -> 더이상 그룹을 묶으면 안되니까
// 단 경계조건인 ( n == 1, n == k) 같은 경우는 별도 에외 처리