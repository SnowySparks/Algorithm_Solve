#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pdp[100001];
int mdp[100001];
int arr[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int cnt;
    for (int i = 1 ; i <= N ; i++) {
        cin >> cnt;
        if (cnt == 1) arr[i] = 1;
        else arr[i] = -1;
    }
    int answer = 0;
    int _a = 0;
    for (int i = 1 ; i <= N ; i++) {
        pdp[i] = max(pdp[i-1]+arr[i] , arr[i]);
        mdp[i] = max(mdp[i-1]-arr[i] , -arr[i]);
        answer = max(answer,max( pdp[i],mdp[i]));
    }
    cout <<answer;
}