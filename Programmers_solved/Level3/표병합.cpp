#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

string datas[51][51];
pair<int ,int> parent_loations[51][51];

pair<int, int> find (pair<int ,int> a) {
    //부모 위치 리턴 및 갱신
    if (parent_loations[a.first][a.second] == a) return a;
    return parent_loations[a.first][a.second] = find(parent_loations[a.first][a.second]);
}

pair<int, int> find (int a, int b) {
    return find(make_pair(a,b));
}

//순서주의,
void _union(pair<int, int> a, pair<int, int> b) {
    pair<int, int> pa = find(a); //a 위치의 최종 부모값 pa
    pair<int, int> pb = find(b); //b 위치의 최종 부모값 pb
    if (pa == pb) return; //같은 부모 -> 종료

    string v1 = datas[pa.first][pa.second];
    string v2 = datas[pb.first][pb.second];
    // 무조건 pa 
    parent_loations[pb.first][pb.second] = pa;
    if (v1 == "*" && v2 !="*") datas[pa.first][pa.second] = v2;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    //처음엔 전부 자기자신이 부모노드 즉 전부 루트노드
    for (int i = 1 ; i <= 50; i++) {
        for (int j = 1 ; j <= 50; j++) {
            parent_loations[i][j] = {i,j};
            datas[i][j] = "*"; //초기화
        }
    }
    vector<string> c; //커맨드 저장 
    int now_r, now_c;
    int r1, c1, r2, c2;
    string back_up;
    for (auto e : commands) {
        //커맨드 추출
        stringstream ss(e);
        while(getline(ss,e,' ')) {
            c.push_back(e);
        }
        //최종 부모 노드 위치에 데이터 갱신
        if (c[0] == "UPDATE") {
            //숫자가 있음 - 해당하는 위치의 부모 위치의 데이터를 갱신
            //자기자신 - 자기자신값, 아닌경우 - 부모위치
            if (c.size() == 4) {
                now_r = stoi(c[1]); now_c = stoi(c[2]);
                pair<int, int> par = find({now_r, now_c});
                datas[par.first][par.second] = c[3];
            }
            //무지성으로 해당되는 모든 문자열을 바꿀 문자열로 교체
            else {
                for (int i = 1 ; i <= 50 ; i++) {
                    for (int j = 1 ; j <= 50; j++) {
                        if (datas[i][j] == c[1]) datas[i][j] = c[2];
                    }
                }
            }
        }
        //해당하는 두 위치의 부모 좌표를 처리
        else if (c[0] == "MERGE") {
            r1 = stoi(c[1]); c1 = stoi(c[2]); r2 = stoi(c[3]); c2=stoi(c[4]);
            _union({r1,c1},{r2,c2});
        }
        else if (c[0] == "UNMERGE") {
            //해당 위치의 최종 부모 노드를 찾음
            pair <int, int> root = find({stoi(c[1]),stoi(c[2])});
            //해당 데이터 복원
            back_up = datas[root.first][root.second];
            //parent_location 값이 root이면 전부 값을 자기자신으로 바꾸고 데이터를 초기화
            for (int i = 1 ; i <= 50; i++) {
                for (int j = 1 ; j <= 50 ; j++) {
                    if (find(parent_loations[i][j]) == root) {
                        datas[i][j]="_";//삭제대상
                    }
                }
            }
            for (int i = 1 ; i <= 50; i++) {
                for (int j = 1 ; j <= 50 ; j++) {
                    if (datas[i][j] == "_") {
                        datas[i][j] = "*";
                        parent_loations[i][j] = {i,j};
                    }
                }
            }
            //마지막 위치에는 해당 데이터 삽입
            datas[stoi(c[1])][stoi(c[2])] = back_up;
        }
        else if (c[0] == "PRINT"){
            //해당하는 위치의 부모에 위치한 데이터를 가져옴
            pair<int ,int> pr = find(stoi(c[1]),stoi(c[2]));
            back_up = datas[pr.first][pr.second];
            //데이터 없으면 
            if (back_up == "*") answer.push_back("EMPTY");
            else answer.push_back(back_up);
        } 
        c.clear(); //커맨드 추출 벡터 초기화  
    }
    return answer;
}