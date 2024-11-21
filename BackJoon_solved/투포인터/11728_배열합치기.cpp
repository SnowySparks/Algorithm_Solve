#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000000];
int b[1000000];

int main(void) {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
    int na, nb; cin >> na >> nb;
    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >>b[i];
    }
    int la = 0 , lb = 0;

    while (la < na && lb < nb) {
        if (a[la] <= b[lb]) {cout << a[la] <<' '; la++;}
        else {cout << b[lb]<<' '; lb++;}
    }
    if (la == na) {
        for (int i = lb ; i <nb ; i++) {cout << b[i] << ' ';}
    }
    else {
        for (int i = la ; i < na ; i++) {cout << a[i] << ' ';}
    }
    return 0;
}