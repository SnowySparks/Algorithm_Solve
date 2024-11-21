#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<int> arr(N);
    vector<int> rank;
    set<int> data;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        data.insert(arr[i]);
    }

    for (auto e : data) {
        rank.push_back(e);
    }

    for (int i = 0; i < N; i++) {
        cout << lower_bound(rank.begin(), rank.end(),arr[i]) - rank.begin()<<' ';
    }
    return 0;
}