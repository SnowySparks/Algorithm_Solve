#include <iostream>
#include <cstring>
#include <unordered_map>
#include <bitset>
using namespace std;
typedef pair<int ,int> pii;
const int inf = 1e9 + 7;
int n;
int arr[200'002];
int parent[200'002];
bitset<200'002> v;
unordered_map<int, int> beforeXSet; // y위치, idx

int findp(int idx) {
    if (idx == parent[idx]) return idx;
    return parent[idx] = findp(parent[idx]);
}

bool isSameParent(int idxA, int idxB) {
    return findp(idxA) == findp(idxB);
}

void unite(int idxA, int idxB) {
    idxA = findp(idxA);
    idxB = findp(idxB);
    if (isSameParent(idxA, idxB)) return;
    parent[max(idxA, idxB)] = min(idxA, idxB);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    int ans = 0;
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        parent[i] = i;
    }
    parent[n+1] = n+1;
    arr[0] = inf;
    arr[n+1] = -1;

    while (r <= n) {
        r++;
        if (arr[r] <= arr[r-1]) {
            //위 아래 방향 병합시도
            for (int idx = l+1; idx < r; ++idx) {
                if (arr[idx]-arr[idx-1] == 1) {
                    unite(idx-1, idx);
                }
            }
            //직전 x에 대한 병합
            for (int idx = l; idx < r; ++idx) {
                if (beforeXSet.find(arr[idx]) != beforeXSet.end()) {
                    unite(idx, beforeXSet[ arr[idx] ]);
                }

            }
            beforeXSet.clear();
            for (int idx = l; idx < r; ++idx) {
                beforeXSet[arr[idx]] = idx;
            }
            l = r;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[findp(i)]) {
            ++ans;
            v[findp(i)] = 1;
        } 
    }
    cout << ans << '\n' << n;
    return 0;
}