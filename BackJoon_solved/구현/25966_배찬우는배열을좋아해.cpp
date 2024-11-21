#include <iostream>
#include <vector>
#include <deque>
#define F(a,b,c) for (int a = b; a < c; a++)
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, q; cin >> N >> M >> q;
    vector<deque<int> > dt(N);
    vector< deque<int> * > ptr(N);
    F(i,0,N) {
        F(k, 0, M) {
            int p ; cin >> p;
            dt[i].push_back(p);
        }
    }
    F(i,0,N) ptr[i] = &dt[i];
    int a, b, c, d;
    F(i,0,q) {
        cin >> a;
        if (!a) {
            cin >> b >> c >> d;
            (*ptr[b])[c] = d;
        }
        else {
            cin >> b >> c;
            swap(ptr[b],ptr[c]);
        }
    }
    F(i,0,N) {
        F(k,0,M) {
            cout << (*ptr[i])[k] << ' ';
        }
        cout << '\n';
    }
}