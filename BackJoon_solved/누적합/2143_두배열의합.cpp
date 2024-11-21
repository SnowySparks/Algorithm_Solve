#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long allA[1001];
long long allB[1001];

map<long long, long long> A, B;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long T; cin >> T;
    long long temp;
    int a,b; cin >> a;

    //누적합 구하기
    for (int i = 1 ; i <= a ; i++) {
        cin >> temp;
        allA[i] = allA[i-1] + temp;
    }
    cin >> b;
    for (int i = 1 ; i <= b ; i++) {
        cin >> temp;
        allB[i] = allB[i-1] + temp;
    }

    //모든 경우의 수 누적합 구하기
    //구할 때마다 틈틈이 map에 그 결과 개수 카운팅 저장

    for (int i = 1 ; i <= a ; i++) {
        for (int j = i; j <= a ; j++) {
            temp = allA[j] - allA[i-1];
            A[temp]++;
        }
    }
    long long ans = 0;
    for (int i = 1 ; i <= b ; i++) {
        for (int j = i; j <= b ; j++) {
            temp = allB[j] - allB[i-1];
            if (A.find(T-temp)!=A.end()) {ans += A[T-temp];}
        }
    }

    cout << ans;
    return 0;
}