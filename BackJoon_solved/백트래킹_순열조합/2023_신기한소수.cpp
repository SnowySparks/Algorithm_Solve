#include <iostream>
#include <string>
#include <vector>
using namespace std;

int case1[] = {2, 3, 5, 7};//첫째 자리에서 소수는 오직 이것
int case_other[] = {1, 3, 5, 7, 9}; //2자리수에선 무조건 홀수만 들어가야 함
bool isnotprime[31701];
vector<int> primes;
//루트 10^9 = 31622;

bool isprime(int inp) {
    for (int i = 0 ; primes[i]*primes[i] <= inp && i < primes.size(); i++) {
        if (inp % primes[i] == 0) return false;
    } return true;
}
void dfs(int N, int cnt, int num) {
    if (N == cnt) {
        cout << num <<'\n'; return;
    }

    if (cnt == 0) {
        for (int i = 0; i < 4 ; i++) {
            dfs(N, cnt+1, case1[i]);
        }
    }
    else {
        for (int k = 0 ; k < 5 ; k++) {
            num = num * 10 + case_other[k];
            if (isprime(num)) {dfs(N, cnt+1, num);}
            num = num/10;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N ; cin >> N;
    //에라토스테네스체
    for (int i =2 ; i*i<=31700; i++) {
        if (isnotprime[i]) continue;
        for (int j = i*i ; j <= 31700; j+=i) {
            isnotprime[j] = true;
        }
    }
    for (int i = 2 ; i <= 31700 ; i++) {if (isnotprime[i] == false) primes.push_back(i);}
    dfs(N,0,0);
    return 0;
     
}