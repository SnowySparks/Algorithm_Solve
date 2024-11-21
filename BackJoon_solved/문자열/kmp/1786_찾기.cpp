#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> makepi(const string &a) {
    int ln = (int) a.size(), j = 0; // _pi[i] 에 넣을 값, 즉 prefix == suffix 최대길이에 대한 것 , 동시에 0 ~ j-1부분이 그 구간인 것
    vector<int> _pi(ln,0); // a[0:i] 중 prefix == suffix 가 되는 가장 큰 prefix 길이
    for (int i = 1 ; i < ln ; i++) {
        while (j > 0 && a[i]!=a[j]) j = _pi[j-1]; // a[i]=/=a[j] 인 경우 적어도 [0:j-1]는 대칭성이 보장된다는 의미. (또한 suffix랑도 매칭)
        //즉 j = pi[j-1]로 이동하여 오직 prefix == suffix 가 보장되는 파트부분만 탐색함
        if (a[i] == a[j]) _pi[i] = ++j; //
    }
    return _pi;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a, b; int j = 0;
    getline(cin,a); getline(cin,b);
    vector<int> pi = makepi(b);
    vector<int> ar((int)a.size(), 0);
    vector<int> ans;

    //kmp 탐색도 pi 찾듯이 처리하기
    for (int i = 0 ; i < (int)a.size(); i++) {
        while( j > 0 && a[i]!=b[j]) j = pi[j-1];
        if (a[i] == b[j]) j++;
        if (j == (int)b.size()) {ans.push_back(i-j+2); j = pi[j-1];}
    }
    cout << (int) ans.size() <<'\n';
    for (int e : ans) cout << e <<' ';
    return 0;
}