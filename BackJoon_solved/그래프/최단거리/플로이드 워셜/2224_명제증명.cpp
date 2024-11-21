#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#define inf 10001
using namespace std;
int dt[52][52]; //알파벳 26개 (대 소),

int chartonum(char a) {
    if (a >= 'A' && a <= 'Z') {
        return a - 'A';
    }
    return a - 'a' + 26;
}

char inttochar(int a) {
    char u;
    if (a < 26) u = 'A' + a;
    else u = 'a' + (a-26);
    return u;
}  

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    string inp;
    char a,b; int n1, n2;
    vector<pair<char, char> > save;
    for (int i = 0 ; i < 52 ; i++) {
        for (int j = 0 ; j < 52 ; j++) {
            dt[i][j] = inf;
        } dt[i][i] = 0;
    }
    
    while (N--) {
        cin >> a >> inp >> b;
        if (a==b) continue;
        n1 = chartonum(a); n2 = chartonum(b);
        dt[n1][n2] = 1;
    }
    
    for (int i = 0 ; i < 52 ; i++) {
        for (int j = 0 ; j < 52 ; j++) {
            for (int k = 0 ; k <52; k ++) {
                dt[j][k] = min(dt[j][k] , dt[j][i] + dt[i][k]);
            }
        }
    }

    for (int i = 0 ; i < 52 ; i++) {
        for (int j = 0 ; j < 52 ; j++) {
            if (dt[i][j] > 0 && dt[i][j] < inf) {
                save.push_back({inttochar(i),inttochar(j)});
            }
        }
    }
    cout << save.size()<<'\n';
    for (auto e : save) {
        cout << e.first << " => " << e.second << '\n';
    }
    
    return 0;
}

