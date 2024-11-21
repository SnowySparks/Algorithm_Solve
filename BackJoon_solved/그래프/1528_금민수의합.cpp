#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

pair<int,int> arr[1000001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for (int i = 0; i <= N; i++) {
        arr[i] = {-1,-1};
    }
    arr[4] = {1,0}, arr[7] = {0,1};

    queue< pair<int,int> > q;
    q.push({1,0}); q.push({0,1});

    while (!q.empty()) {
        int four = q.front().first;
        int seven = q.front().second;
        q.pop();
    }
}