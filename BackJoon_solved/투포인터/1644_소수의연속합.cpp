#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isprime[4000001];

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n ; cin >> n;
	//0과 1은 소수가아님
	for (long long i = 2 ; i*i<= 4000000 ; i++) {
		if (!isprime[i]) {
		for (long long j = i*i ; j <= 4000000; j+=i) {
			isprime[j] = true;
		}
	}}
	vector<int> primes;

	for (int i = 2 ; i <= n ; i++) {
		if (!isprime[i]) primes.push_back(i);
	}
	int a=0,b=0,count=0;
	long long sum=0;

	while (a<=b) {
		if (sum > n) {
			sum-=primes[a++];
		}
		else if (b==primes.size()) break;
		else {
			sum+=primes[b++];
		}
		  
		  if (sum == n) count++;
	}
	cout << count;
	return 0;


}
