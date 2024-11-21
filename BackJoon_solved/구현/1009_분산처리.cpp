#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int>> dt;

int one_number(int a, int b) {
    a=a%10;
    if (a==0) return 10;
    if (a==1 || a==5 || a==6) return a;
    else if (a==2 || a==3 || a==7 || a==8) return dt[a][(b-1)%4];
    return (b%2==1) ? a : (a*a)%10;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    dt.insert({2,{2,4,8,6}});
    dt.insert({3,{3,9,7,1}});
    dt.insert({7,{7,9,3,1}});
    dt.insert({8,{8,4,2,6}});
    int N ; cin >> N;
    int a,b;
    while(N--) {
        cin >> a>>b;
        cout << one_number(a,b) <<'\n';
    }
}