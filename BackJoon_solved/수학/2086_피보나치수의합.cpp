#include<iostream>
#include<vector>
using namespace std;
using ul = unsigned long;

typedef vector<vector<ul>> matrix;
const ul mod = 1e9;
const ul dv = 15 * mod / 10;
ul n;

//연산자 오버로딩
matrix operator * (matrix& a, matrix& b)
{
	matrix c(2, vector<ul>(2,0));

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];

			c[i][j] %= mod;
		}
	return c;	
}
ul fibo(ul n) {
    if (n == 0) return 0;
    matrix res = {{1,0},{0,1}};
    matrix mul = {{1,1},{1,0}};
    while (n) {
        if (n&1) res = res* mul;
        mul = mul * mul;
        n/=2;
    }
    return res[0][1];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ul a, b; cin >> a >> b;
    cout << ( fibo(b+2) % mod - fibo(a+1) %mod + mod ) % mod;
    return 0;
}