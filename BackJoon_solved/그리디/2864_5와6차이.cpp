#include <iostream>
#include <string>
#include <algorithm>
#define F(a) for (int i = 0 ; i < a ; i++)
using namespace std;

void change(string & p, char f, char t) {
    F(p.size()) if (p[i] == f) p[i] = t; }
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    int r1, r2;
    change(a,'6','5'); change(b,'6','5');
    cout << stoi(a)+stoi(b) << ' ';
    change(a,'5','6'); change(b,'5','6');
    cout << stoi(a)+stoi(b); return 0;
}