#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1365번 문제도 이 코드와 완전히 동일함

int arr[100000];
vector<int> L;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<int>::iterator it;
    int answer = -1;
    for (int i = 0 ; i < N ; i++) {
        cin >> arr[i];
        //오름차순으로 처리하는 것 - 가장 긴 증가하는 수열
        if (L.empty() || L.back() < arr[i]) {
            L.push_back(arr[i]);
            answer = max(answer,(int)L.size());
        }
        else {
            it = lower_bound(L.begin(),L.end(),arr[i]);
            *it = arr[i];
            answer = max(answer,(int) (it - L.begin()+1));
        }
    }
    cout << N - answer;
    return 0;
}