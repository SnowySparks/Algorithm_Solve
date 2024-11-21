#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 2000000000


int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int N,temp,a,b;
    cin >> N;

    priority_queue<int> mpq;
    priority_queue<int,vector<int>,greater<int> > npq;

    while (N--){
        cin >> temp;
        if (mpq.size() > npq.size()) {
            npq.push(temp);
        }
        else  mpq.push(temp);

        if ( !mpq.empty() && !npq.empty() && mpq.top() > npq.top() ) {
            a= mpq.top();
            b=npq.top();
            mpq.pop();npq.pop();

            mpq.push(b);npq.push(a);
        }
        cout << mpq.top() <<'\n';
    }
    return 0;
}