#include <string>
#include <vector>
#include <set>
using namespace std;

//현재 양수, 현재 늑대수, 현재 위치, 방문한 곳, 맵, 정보
int max_sheep = 0;
void dfs(int sheep, int wolf, int now_node, vector<int> nextnode, const vector<int> &info, const vector<vector <int> > & tb ) {
    //현재 위치에 대한 데이터 갱신
    if (info[now_node] == 0) sheep++; else wolf++;
    max_sheep = max(max_sheep, sheep);
    if (sheep <= wolf) return; //늑대 >= 양 -> 즉각종료
    //다음에 갈 노드와 이에 가는 곳이 
    for (int i = 0 ; i <nextnode.size(); i++) {
        vector<int> next = nextnode; //가야할 곣 데이터 복사
        next.erase(next.begin()+i);//현재 노드 제거
        for (int k = 0 ; k < tb[nextnode[i]].size() ; k++) {
            next.push_back(tb[nextnode[i]][k]);
        }
        dfs(sheep,wolf,nextnode[i],next,info,tb);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int> > tb (info.size());
    for (auto e : edges) {
        tb[e[0]].push_back(e[1]);
    }
    vector<int> start_nextnode;
    for (int e : tb[0]) {  
        start_nextnode.push_back(e);
    }
    dfs(0,0,0,start_nextnode,info,tb);
    return max_sheep;
}