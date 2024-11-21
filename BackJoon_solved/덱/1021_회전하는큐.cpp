#include <iostream>
#include <deque>
#include <vector>
#define f(a,b,c) for (int a = b ; a < c ; a++)
using namespace std;
int N, K;
deque<int> lst; 
int main(void) {
    cin >> N >> K;
    vector<int> dt(K);
    f(i,1,N+1) lst.push_back(i);
    f(i,0,K) cin >> dt[i];
    int ans = 0;
    int loc;
    f(i,0,K) {
        for (loc= 0; loc < lst.size(); loc++) {
            if (lst[loc] == dt[i]) break;
        }
        if (loc <=lst.size()/2) {
            ans += loc;
            f(i,0,loc) {
                lst.push_back(lst.front());
                lst.pop_front();
            }
            lst.pop_front();
        }
        else {
            ans += (lst.size() - loc);
            f(i,0,lst.size() - loc) {
                lst.push_front(lst.back());
                lst.pop_back();
            }
            lst.pop_front();            
        }
    }
    cout << ans; return 0;
}