#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N ; cin >> N;
    int T;
    char inp1; int inp2;
    multiset<int> table;
    multiset<int>::iterator it;

    while (N--) {
        cin >> T;
        while (T--) {
            cin >> inp1 >> inp2;
            if (inp1 == 'I') {
                table.insert(inp2);
            }
            else if (inp1 == 'D') {
                if (table.empty()) {}
                else if (inp2 == 1) {
                    it = table.end(); it--;
                    table.erase(it);
                }
                else {
                    table.erase(table.begin());
                }
            }
        }
        if (table.empty()) {cout <<"EMPTY\n";}
        else {
            it= table.end() ; it--;
            cout << *it << ' ' << *table.begin() <<'\n';
        }
        table.clear();
    }
    return 0;
}