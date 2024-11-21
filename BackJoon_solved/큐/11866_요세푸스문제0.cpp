#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N,k,t=0;
    cin >> N >>k;
    queue <int> q;
    int temp;

    for (int i=1 ; i<=N ; i++) {
        q.push(i);
    }
    cout <<"<";

    while (!q.empty()) {
        for (int i=1;i<k;i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if (q.size()!=1) {
            cout << ", ";
        }
        q.pop();
    }
    cout << ">";
    
    return 0;
}