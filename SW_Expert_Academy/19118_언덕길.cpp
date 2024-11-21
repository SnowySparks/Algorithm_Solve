#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test_case;
	int T, n; cin>>T;
    vector<int> lst; //최대 증가 순열
    int arr[1000];
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        lst.clear();
        for (int i = 0 ; i < n ; ++i) cin >> arr[i];
        for (int i = 0 ; i < n; ++i) {
            if (lst.empty() || lst.back() < arr[i]) lst.push_back(arr[i]);
            else {
                auto loc = lower_bound(lst.begin(), lst.end(),arr[i]);
                *loc = arr[i];
            }
        }
        cout << '#' << test_case <<' ' << n - (int)lst.size() << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}