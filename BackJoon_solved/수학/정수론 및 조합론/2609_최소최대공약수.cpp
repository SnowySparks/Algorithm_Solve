#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin >> n >> k;

    int min = gcd(n,k);
    int max = (n*k) / min;

    cout << min << '\n';
    cout << max << '\n';


    return 0;

    

}