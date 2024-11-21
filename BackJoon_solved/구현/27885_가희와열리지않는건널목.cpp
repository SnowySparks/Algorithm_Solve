#include <iostream>
#include <algorithm>
#include <vector>
#define f(a,b,c) for (int a=b;a<c;a++)
using namespace std;

bool isclosed[86400];

int strtoint(const string &s) {
    return stoi(s.substr(0,2)) * 3600 + stoi(s.substr(3,2)) * 60 + stoi(s.substr(6,2));
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int c,h; cin >> c >> h;
    string inp;
    f(i,0,c) {
        cin >> inp; int start = strtoint(inp);
        f(k,start,start+40) isclosed[k]= true;
    }
    f(i,0,h) {
        cin >> inp; int start = strtoint(inp);
        f(k,start,start+40) isclosed[k]= true;
    }
    int cnt = 0;
    f(i,0,86400) if (!isclosed[i]) cnt++;
    cout << cnt;
    return 0;

}