#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int x[10001];
int y[10001];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i]; }
    x[N] = x[0]; y[N] = y[0];
    long double answer = 0;
    for (int i = 0; i < N; i++) {
        answer += x[i]*y[i+1];
    }
    for (int i = 0; i < N; i++) {
        answer -= y[i]*x[i+1];
    }
    answer /=2;

    printf("%.1Lf",abs(answer));
    return 0;
}