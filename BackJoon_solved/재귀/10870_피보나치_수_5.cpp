#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int pb(int a) {
    if (a==0) return 0;
    if (a==1) return 1;
    return pb(a-1) + pb(a-2);
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int a;
    cin >> a;
    cout << pb(a) << endl;

    return 0;

}