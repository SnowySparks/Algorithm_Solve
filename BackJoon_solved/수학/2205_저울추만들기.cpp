#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cout.tie(NULL);
    vector<int> lst;
    for (int i = 2 ; i < 100000 ; i*=2) {
        lst.push_back(i);
    }
    int N; cin >> N;
    for (int i = 1; i <=N;i++) {
        cout << *upper_bound(lst.begin(), lst.end(),i+1) - i <<'\n';
    }
    return 0;
}