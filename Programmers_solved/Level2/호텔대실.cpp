#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int strtoint(const string &a) {
    int hr = stoi(a.substr(0,2));
    int mr = stoi(a.substr(3,2));
    return hr*60+mr;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int> > lst;
    for (auto e : book_time) {
        lst.push_back( { strtoint(e[0]) , strtoint(e[1])});
    }
    sort(lst.begin(), lst.end());
    int loc = 0;
    priority_queue<int , vector<int>, greater<> > q;
    while(loc < lst.size()) {
        if (q.empty() || q.top() > lst[loc].first ) {
            q.push(lst[loc++].second + 10);
        }
        else {
            q.pop();
            q.push(lst[loc++].second + 10);
        }
    }
    return q.size();

}