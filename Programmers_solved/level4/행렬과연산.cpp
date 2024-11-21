#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer(rc.size());
    vector< deque<int> > middle (rc.size());
    //deque 넣기 양옆
    deque<int> left, right;
    deque< deque<int> * > point_mid;
    for (int i = 0 ; i < rc.size(); i++) {
        left.push_back(rc[i][0]);
        right.push_back(rc[i][(rc[0].size())-1]);
        for (int p = 1 ; p < rc[0].size() -1 ; p++) {
            middle[i].push_back(rc[i][p]);
        }
        point_mid.push_back(&middle[i]);
    }
    for (int i = 0 ; i < operations.size() ; i++) {
        if (operations[i][0] == 'S') { //RotateRow
            left.push_front(left.back()); left.pop_back();
            right.push_front(right.back()); right.pop_back();
            point_mid.push_front(point_mid.back()); point_mid.pop_back(); 
        }
        else { //clock 이동
            point_mid.front()->push_front(left.front()); left.pop_front();
            point_mid.back()->push_back(right.back()); right.pop_back();
            left.push_back(point_mid.back()->front()); point_mid.back()->pop_front();
            right.push_front(point_mid.front()->back()); point_mid.front()->pop_back();
        }
    }
    int p;
    for (int i = 0 ; i < rc.size() ; i++) {
        for (int j = 0 ; j < rc[0].size(); j++) {
            if (j==0) answer[i].push_back(left.at(i));
            else if (j== rc[0].size()-1) answer[i].push_back(right.at(i));
            else {
                answer[i].push_back(point_mid[i]->at(j-1));
            }
        }
    }
    return answer;
}