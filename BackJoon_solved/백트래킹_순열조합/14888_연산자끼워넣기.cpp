#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 2000000000
#define MIN -2000000000

int n;
int ar[11];
int add, sub, mul, divi;
int maxv = MIN;
int minv = MAX;

void dfs(int cnt, int sum_ar)
{
	if (cnt == n)
	{
		maxv = max(maxv, sum_ar);
		minv = min(minv, sum_ar);
	}
	else
	{
		if (add > 0)
		{
            add--;
			dfs(cnt + 1, sum_ar + ar[cnt]);
			add++;
		}

		if (sub > 0)
		{   
            sub--;
			dfs(cnt + 1, sum_ar - ar[cnt]);
			sub++;
		}

		if (mul > 0)
		{   
            mul--;
			dfs(cnt + 1, sum_ar * ar[cnt]);
			mul++;
		}

		if (divi > 0)
		{
            divi--;
			dfs(cnt + 1, sum_ar / ar[cnt]);
			divi++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	cin >> add >> sub >> mul >> divi;
	dfs(1, ar[0]);
	cout << maxv << '\n' << minv;
	return 0;
}