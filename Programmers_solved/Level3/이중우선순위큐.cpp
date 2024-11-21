#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    
    multiset<int> ms;
    vector<int> answer;
    
    for (auto e : operations) {
        if (e[0]=='I') {
            ms.insert(stoi(e.substr(e.find(' '),string::npos)));
        }
        else {
            if (e[2]=='-' && (!ms.empty())) {
                ms.erase(ms.begin());
            }
            else {
                if (!ms.empty()) {
                    auto p = ms.end();
                    p--;
                    ms.erase(p);
                }
            }
        }
    }
    
    if (ms.empty()){
        return vector<int> {0,0};
    }
    
    if (ms.size()==1) {
        answer.push_back(*(ms.begin()));
        answer.push_back(0);
        return answer;
    }
    
    answer.push_back(*(ms.rbegin()));
    answer.push_back(*(ms.begin()));
    return answer;
}