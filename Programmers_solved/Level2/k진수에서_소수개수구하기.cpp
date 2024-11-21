#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

bool isprime (long long a) {
    if (a < 2) return false;
    for (long long i = 2 ; i*i <= a ; i++) {
        if (a % i == 0) return false;
    } return true;
}


int solution(int n, int k) {
    int answer = 0;
    string n_num = "";
    stack<int> r;
    while (n!= 0) {
        r.push(n%k);
        n=n/k;
    }
    while (!r.empty()) {
        n_num.push_back(r.top() + '0' );
        r.pop();
    }

   
    long long a1 = 0;
    for (char e : n_num) {
        if (e != '0') {
            a1 = ((a1 * 10) + (e-'0'));
        }
        else if (e=='0') {
            if (isprime(a1)) answer++;
            a1 = 0;
        }
    }
    if (isprime(a1)) answer++;
    return answer;
    
}