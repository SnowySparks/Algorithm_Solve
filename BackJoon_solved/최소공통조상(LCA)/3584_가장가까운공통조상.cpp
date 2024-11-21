#include <iostream>
#include <vector>
using namespace std;

int parent[10001];
bool v[10001];

//한쪽의 자식에서 루트까지 
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int a, b;
    int N;
    while(T--) {
        int N; cin >> N;
        for (int i = 1 ; i <= N ; i++) {parent[i] = i; v[i] = false; }
        for (int i = 1 ; i <= N-1 ; i++) {
            cin >> a >> b;
            parent[b] = a;
        }
        int s, e; cin >> s >> e;
        v[s] = true;
        while(s != parent[s]) {
            s = parent[s];
            v[s] = true;
        }
        while(!v[e]) e = parent[e];
        cout << e <<'\n';
    }
    return 0;
}