#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    int S, K; cin >> S >> K;
    int remains = S;
    vector<long long > lst;
    for (int i = 0 ; i < K ; i++) {
        lst.push_back(S/K);
        remains -= (S/K);
    }
    int loc = 0;
    while (remains > 0) {
        lst[loc]++;
        loc = loc == lst.size() -1 ? 0 : loc+1;
        remains--;
    }
    long long answer = 1;
    for (auto e : lst) {
        answer*=e;
    } cout << answer; return 0;
}