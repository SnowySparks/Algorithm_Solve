#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define f(a,b,c) for(int a = b; a < c; a++)
using namespace std;

int toint(const string &a) {
    int p = 0;
    p+= stoi(a.substr(0,1));
    p*=60;
    p+= stoi(a.substr(2,2));
    p*=1000;
    p+= stoi(a.substr(5,3));
    return p;
}
const int score[9] = {10, 8, 6, 5, 4, 3, 2, 1, 0};
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int s[2] = {0,0};
    string inp[8];
    pair<int, char> dt[8];
    f(i,0,8) getline(cin, inp[i]);
    f(i,0,8) {
        dt[i].first = toint(inp[i]);
        dt[i].second = inp[i].back(); };
    sort(dt,dt+8);
    int first;
    f(i,0,8) {
        int loc = dt[i].second == 'B' ? 1 : 0;
        s[loc] += score[i]; }
    if (s[0] > s[1]) cout <<"Red";
    else if (s[0] < s[1]) cout<<"Blue";
    else {
        cout << (dt[0].second == 'B' ? "Blue" : "Red");
    }
    return 0;
}