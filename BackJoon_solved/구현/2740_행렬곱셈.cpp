#include <iostream>
#include <vector>
#define F(a,b,c) for(int a = b; a < c; a++)
using namespace std;
int a[100][100];
int b[100][100];
int c[100][100];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    F(i,0,N) {
        F (k, 0, M) cin >> a[i][k];
    }
    int K; cin >> M >> K;
        F(i,0,M) {
        F (k, 0, K) cin >> b[i][k];
    }
    F(i, 0, N) {
        F(k, 0, K) {
            F(t, 0, M) {
                c[i][k] += a[i][t]*b[t][k];
            }
        }
    }
    F(i,0,N) {
        F(k, 0, K) {
            cout << c[i][k] << ' ';
        } cout << '\n';
    }
    return 0;
}