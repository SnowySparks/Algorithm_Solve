#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long gcd (long long a, long long b) {
    long long c;
    while (b!=0) {
        c= a%b;
        a=b;
        b=c;
    } return a;
}

int main(void) {
    long long a, b; cin >> a >> b;
    long long g = gcd(a, b);
    string answer = "";
    for (long long i= 0 ; i < g ; i++) {
        answer+="1";
    }
    cout << answer;
    return 0;
}