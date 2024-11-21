#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int dt[100];
int dt_gtd[100];

int gcd_f(int a, int b) {
    if (b==0) return 0;
    int temp;
    while (b>0) {
        temp = a;
        a= b;
        b = temp % a;
    }
    return a;    
}


int main(void) {
    int n;
    cin >> n;
    set<int> gcd_list;
    for (int i = 0; i < n; i++) {
        cin >> dt[i];
    }
    sort(dt,dt+n);
    int g = dt[1]-dt[0];

    for (int i = 2; i < n; i++) {
        g = gcd_f(g, dt[i] - dt[i-1]);
    }//입력 받은 모든 수의 최대공약수

    for (int i = 2 ; i*i <= g; i++) {
        if (g % i == 0) {
            gcd_list.insert(i);
            gcd_list.insert(g/i);
        }
    }
    gcd_list.insert(g);

    for (auto e : gcd_list) {
        cout << e << ' ';
    }
}