#include <string>
#include <vector>
using namespace std;

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool check1(int x1, int y1, int x2, int y2, vector<string>room) {
    int dist=distance(x1, y1, x2, y2);
    if (dist==1) {

        return false;
    }
    if (dist >2) {
        return true;
    }
    else {
        if (x1==x2) {
            return room[x1][(y1+y2)/2]=='X'?true:false;
        }
        else if (y1==y2) {

            return room[(x1+x2)/2][y1]=='X'?true:false;
        }
        else if (room[x1][y2]=='X' & room[x2][y1]=='X') {
            return true;
        }

        return false;
    }
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<pair<int,int>> people_loc;
    bool endflag=false;
    for (auto e : places) {
        endflag=false;
        people_loc.clear();
        for (int i=0;i<5;i++) {
            for (int j=0;j<5;j++) {
                if (e[i][j]=='P') {
                    people_loc.push_back(make_pair(i,j));
                }
            }
        }

        for (int i=0;i<people_loc.size();i++) {
            for (int j=i+1;j<people_loc.size();j++) {
                if (check1(people_loc[i].first,people_loc[i].second,people_loc[j].first,people_loc[j].second,e)==false) {
                    endflag=true;
                    break;
                }
            }
            if (endflag==true) {
                break;
            }
        }
        if (endflag==true) {
            answer.push_back(0);
        }
        else {
            answer.push_back(1);
        }
    }
    return answer;
}