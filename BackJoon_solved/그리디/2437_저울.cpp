#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n ; cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i ++) cin >> arr[i];
    sort(arr.begin(),arr.end()); //정렬

    if (arr.front() != 1) { //추 무게가 2이상 -> 1은 무조건 안됨 ㅇㅇ..
        cout << 1;
        return 0;
    }
    int sum = 1;

    for (int i = 1 ; i< n; i++) {
        //현재 추 무게가 이전까지 무게추들의 총합보다 작으면 , sum+arr[i] 까진 되는거임
        if (sum+1>= arr[i]) sum+=arr[i];
        else break;
    }
    cout << sum+1;
    return 0;
}