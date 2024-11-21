#include <iostream>
#include <vector>
#include <algorithm>
#define _mul 1000
using namespace std;

vector< vector<int> > operator* ( vector<vector<int> > &a, vector<vector<int> > &b) {
    int N = a.size();
    vector< vector<int> > result(N, vector<int>(N,0));
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <N; j ++) {
            for (int k = 0 ; k < N; k ++) {
                result[i][j] += (a[i][k]*b[k][j]);
            }
        }
    }
    return result;
}


int main() {
    int N; long long B; cin >> N >> B;
    vector< vector<int> > orig (N, vector<int>(N));
    vector< vector<int> > mul (N, vector<int>(N,0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <N ; j++) {
            cin >> orig[i][j];
            if (i==j) mul[i][j] = 1;
        }
    }

    while (B>0) {
        if (B %2 == 1) {
            mul = mul * orig;
        }
        orig = orig * orig;
        B/=2;
    }
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            cout << mul[i][j]%1000 <<' ';
        } cout << '\n';
    }
    return 0;
}