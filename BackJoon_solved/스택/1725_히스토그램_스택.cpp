#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

long long N, ans = 0, arr[100002];
stack<long long> s;
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	s.push(0);
	for (int i = 1; i <= N + 1; i++) {
		while (!s.empty() && arr[s.top()] > arr[i]) { //항상 0은 남기면서
			int check = s.top();
			s.pop();
			ans = max(ans, arr[check]*(i - s.top() - 1));
		}
		s.push(i);
	}
	cout << ans;
	
}