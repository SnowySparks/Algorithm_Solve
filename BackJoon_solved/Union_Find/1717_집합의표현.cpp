#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent_tree[1000001]; //해당 인덱스 위치 값은 해당 노드의 최종 부모 노드 값

int find(int n) {
    if ( parent_tree[n] == n ) return n; //부모가 없음 -> 자기자신이 루트
    return parent_tree[n] = find(parent_tree[n]);
}

void _union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    if (px>py) parent_tree[px] = py;
    else parent_tree[py] = px;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    int a,b,c;
    for (int i = 1; i <= n ; i++) parent_tree[i] = i;

    for (int i = 1; i <= m ; i++) {
        cin >> a >> b >> c ;
        if (a == 0) {
            _union(b,c);
        }
        else {
            if (find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}