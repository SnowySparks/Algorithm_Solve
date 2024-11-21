#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int factorial(int a) {
    if (a == 1 || a == 0) return 1;
    else return factorial(a-1) * a;
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int a;
    cin >> a;
    cout << factorial(a) << endl;

    return 0;

}