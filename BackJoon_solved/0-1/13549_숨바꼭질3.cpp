#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
const int d = 1E5+1;

int lst[d]= {0,};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    deque<int> q;
    memset(lst,-1,sizeof(lst));
    int start, end, nxt; cin >> start >> end;
    lst[start] = 0;
    q.push_back(start);

    while (!q.empty()) {
        int loc = q.front() ; q.pop_front();
        if (loc == end) {
            cout << lst[loc];
            break;
        }

       nxt = loc *2;
       if (nxt < d && lst[nxt] == -1) {
        q.push_front(nxt);
        lst[nxt] = lst[loc];
       }
       
    nxt = loc -1;
       if (nxt >= 0 && lst[nxt] == -1) {
        q.push_back(nxt);
        lst[nxt] = lst[loc]+1;
       }
    nxt = loc + 1;
       if (nxt < d && lst[nxt] == -1) {
        q.push_back(nxt);
        lst[nxt] = lst[loc]+1;
       }

    }
    return 0;
}