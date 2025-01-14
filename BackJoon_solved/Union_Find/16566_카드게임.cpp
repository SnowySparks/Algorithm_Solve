#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
int n, m, k;
vector<int> p; // 부모 노드
vector<int> card; // 카드
vector<int> arr; // k개의 수
int parent(int node) {
    if (p[node] == node) return node;
    return p[node] = parent(p[node]);
}

bool unite(int fr, int to) { // fr 이 to의 자식이 되는 꼴
    int p_fr = parent(fr);
    int p_to = parent(to);
    if (p_fr == p_to) return false;
    p[p_fr] = p_to;
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m >> k;
    p.resize(m);
    card.resize(m);
    arr.resize(k);
    f(i, 0, m) {
        p[i] = i;
        cin >> card[i];
    }
    for (int &a : arr) cin >> a;
    sort(card.begin(), card.end());
    for (int &num : arr) {
        int loc = upper_bound(card.begin(), card.end(), num) - card.begin();
        int pLoc = parent(loc);
        cout << card[pLoc] << '\n';
        unite(pLoc, pLoc + 1);
    }

    return 0;
}