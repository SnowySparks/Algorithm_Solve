#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const vector<int> &a, const vector<int> &b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    auto wonho = scores[0];
    sort(scores.begin()+1, scores.end(),comp);
    int max_w = scores[1][0]; //근무점수
    int max_d = 0; //동료점수
    for (int i = 1 ; i < scores.size() ; i++) {
        if (wonho[0] < scores[i][0] && wonho[1] < scores[i][1]) {
            return -1;
        }
        max_d = max(max_d,scores[i][1]);
        if (scores[i][1] < max_d) continue;

        if (wonho[0] + wonho[1] < scores[i][0] + scores[i][1]) {
            answer++;
        }
    }
    return answer;
}