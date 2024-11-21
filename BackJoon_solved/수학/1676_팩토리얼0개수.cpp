#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//!(inp)의 2,5의 인수를 구하는 방식
//이렇게 하면 !20억도 30회 만에 처리 가능
pair<long long, long long > twofive(long long inp) { 
    pair<long long, long long> ans = {0,0};
    for (long long i = 2; i <= inp; i*=2) {
        ans.second += (inp/i);
    }
    for (long long i = 5; i <= inp; i*=5) {
        ans.first += (inp/i);
    }
    return ans;
}

pair<long long, long long> operator+ (const pair<long long, long long> &a, const pair<long long, long long> &b) {
    pair<long long, long long> ans = {a.first+b.first,a.second+b.second};
    return ans;
}
pair<long long, long long> operator- (const pair<long long, long long> &a, const pair<long long, long long> &b) {
    pair<long long, long long> ans = {a.first-b.first,a.second-b.second};
    return ans;
}

int main(void) {
    long long N, M; cin >> N >> M;
    pair<long long, long long> n = twofive(N); 
    pair<long long, long long> nm = twofive(N-M);
    pair<long long, long long> m = twofive(M);

    pair<long long, long long> ans = (n-nm)-m;
    cout << min(ans.first, ans.second);
    return 0;
    
}