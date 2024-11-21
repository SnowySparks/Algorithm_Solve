#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lst[100000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long left = 1;
    int N; long long M;
    cin >> N >> M;
    for (int i = 0; i < N ; i++) {
        cin >> lst[i];
    }
    long long right = *max_element(lst,lst+N) * M;
    long long answer = right;
    long long temp = 0;
    while (left <= right) {
        temp = 0;
        long long mid = (left + right)/2;
        for (int i = 0 ; i < N ; i++) {
            temp += mid/lst[i];
            if (temp > M ) break;
        }
        if (temp < M) {
            left = mid + 1;}
        else {
            answer = min(answer, mid);
            right = mid - 1;
        } 
    }
    cout << answer;
    return 0;
}