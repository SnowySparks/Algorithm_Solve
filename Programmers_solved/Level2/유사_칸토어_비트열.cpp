#include <string>
#include <cmath>
#include <vector>

using namespace std;

long long p(int a, int b) {
    long long ans =1;
    for (int i = 0 ; i < b ; i++) ans*=a;
    return ans;
}

long long sol(long long x) {
    if (x <= 5) return (x<=2) ? x : x-1;
    int base = (int) (log10(x)/log10(5));
    int d = x/p(5,base);
    int r = x%p(5,base);
    long long ans = p(4,base) * ((d>2)?d-1:d);

    if (d==2) return ans;
    else return ans + sol(r);
}

int solution(int n, long long l, long long r) {
    int answer = sol(r)-sol(l-1);
    return answer;
}