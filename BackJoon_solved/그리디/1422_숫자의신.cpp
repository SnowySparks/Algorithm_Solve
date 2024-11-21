#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answers;
bool comp(const string &a , const string &b) {
    return a+b > b+a;
}

int main(void) {
    int K; int N; cin >> K >> N;
    vector<string> lst(K);
    string chosen;
    string inp;
    for (int i = 0; i < K ; i++) {
        cin >> inp;
        answers.push_back(inp);
        if (chosen.size() < inp.size() || chosen.size() == inp.size() && chosen < inp) chosen = inp;
    }
    for (int i = 0; i < N-K; i++) {
        answers.push_back(chosen);
    }
    sort(answers.begin(), answers.end(),comp);
    for (auto e : answers) cout << e;
    return 0;
}