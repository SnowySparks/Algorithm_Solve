용어  
트리 간선 : DFS Spaaning Tree상의 간선
순방향 간선 : "트리 간선" 이외의 DFS 방문 상 부모에서 자식으로 향하는 간선  

역방향 간선 : Spanning Tree의 자손에서 선조로 연결되는 간선  

교차 간선 : 자손과 손조 관계가 아닌 정점들 간의 연결된 간선


# BCC 

Biconnected Component는 biconnected (단절점이 없는) maximal subgraph이다.
BCC는 그래프를 단절점/단절선을 기준으로 쪼갠 후, 이를 기준으로 정점/간선들을 묶어 트리로 만듬.

1. 해당 집합에서 어떤 정점 하나를 삭제하더라도, 남은 정점들은 서로 연결되어 있다.
2. 해당 집합에 다른 정점들을 추가하더라도 1을 만족하지 않는다. (1번을 만족하는 최대 크기의 집합이다)

따라서 1, 2 조건에 의해서 BCC는 가능한 큰 그룹으로 이루어짐  
즉 BCC는 무향그래프에서 "가장 큰" 사이클을 이루는 sub_graph

SCC와 매우 유사한 방식이 있으나 SCC는 오직 정점에 대해서 탐색하지만 BCC는 간선기준, 정점기준 방식 알고리즘이 있음

정점(노드)는 여러개의 BCC 그룹에 속할 수 있지만 간선은 __*오직 한개의 BCC*__ 에만 속하니  
보통 간선을 분리하는 것이 자연스러움

BCC 그룹끼리 간에는 트리 구조가 형성되어짐

## 단절점 단절선
둘다 해당 정점, 간선을 제거할 경우


## 알고리즘 방식

O(V + E) 복잡도로 해결이 가능함

보통 2가지 BCC 형성 하는 방법이 있음
1. Edge disjoint BCC : 단절점을 기준을 쪼갠 간선의 집합
2. Vertex disjoint BCC : 단절선을 기준으로 쪼갠 간선의 집합  


Vertex disjoint BCC의 경우에는 단절선을 모두 자른 후, 남은 컴포넌트들이 하나의 BCC를 구성하고, 이를 하나의 정점으로 압축한다면 트리가 됨

Edge disjoint BCC의 경우에는 BCC가 간선의 집합으로 구성되어 있기 때문에, 한 정점은 여러 개의 BCC에 포함될 수 있다. 특히, 그러한 정점들은 모두 단절점이다.  
한 정점이 여러 개의 BCC에 포함될 수 있다는 점 때문에 이 경우에는 단순히 정점들을 압축하는 것으로 트리를 만들 수 없다.  
따라서, 트리를 각 색별 BCC를 대표하는 노드 하나와, 이 노드에 해당 BCC에 속하는 정점들을 성게 모양으로 연결하여 원래 그래프의 노드들과 BCC 색 노드들이 이분적으로 연결되어 있는 트리의 꼴이 나오게 된다.  

방법은 SCC와 비슷하게 DFS Spanning Tree를 이용함 

그래프를 DFS로 탐색하면서
1. 먼저 방문하지 않은 정점에 대해서 정점 방문 순서를 기록함. (DFS_num[v] 라고 가정)
  그리고 간선을 탐색하는 순서대로 스택을 저장함 (node, node) 형태로 스택에 넣음

2. DFS탐색으로 인한 Spanning Tree에서 현재 정점 V를 루트로 하는 서브 트리에 속한 (단 V는 제외) 정점의 역방향 간선으로 이동 할 수 있는 모든 정점들의 u에 대해서  
min(DFS_num[u])의 결과를 DFS_min[v]라고 가정

3. DFS를 하던 도중, 정점 v 에서 정점 nv를 탐색했을 때, DFS_num[v]≤DFS_min[nv]라면, 스택 내에서 (v,nv)보다 나중에 삽입된 간선은 모두 하나의 BCC에 속함
이 간선들을 전부 stack에서 제거하면 해당 간선들은 BCC들임

```c++
vector <int> graph[SIZE];
 
vector<vector<pii> > BCC;
 
int DFS_cnt = 1;
int DFS_num[SIZE];
int DFS_min[SIZE];
 
vector<pii> stk;
 
void DFS(int v, int p)
{
    //방문하지 않는 정점 v에 대한 방문 순서를 기록
    DFS_num[v] = DFS_min[v] = DFS_cnt++;

    //자식들에 대한 탐색
    for (int nv : graph[v])
    {
        if (nv == p) continue; //직전 부모 노드에 대해선 스킵 , DFS Spanning Tree상 부모 노드 스킵
        if (DFS_num[v] > DFS_num[nv]) stk.push_back({ v, nv });
        // 아직 방문하지 않은 간선을 스택에 넣기. 트리 접근이기에 
        if (DFS_num[nv]) //역방향 간선탐색.
        {
            DFS_min[v] = min(DFS_min[v], DFS_num[nv]);
        }
        else
        {
            // 순방향 간선 - 정확힌 DFS Tree의 간선 
            DFS(nv, v);
            DFS_min[v] = min(DFS_min[v], DFS_min[nv]);
            // 다음 정점이 DFS트리상 현재 노드의 조상으로 갈 수가 없음을 의미
            //즉 이 경우 BCC를 찾은 거임
            if (DFS_min[nv] >= DFS_num[v])
            {
                BCC.emplace_back();
                while (true)
                {
                    //현재 노드와 탐색중인 자식이 나올 때 까지 pop하고 그것들은 한 그룹 BCC에 담음
                    pii e = stk.back(); stk.pop_back();
                    BCC.back().push_back(e);

                    if (e == pii(v, nv)) break;
                }
            }
        }
    }
}

```
<hr>
다음과 같이 DFS_min배열을 따로 생상하지 않은 대신 
해당 DFS 연산의 Return값을 현재 노드에서 "도달 가능한 가장 작은 방문순서값" 으로 둘 수가 있음

```c++
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
 
const int MAX = 100000;
typedef pair<int, int> P;
 
int V, E, dcnt, dfsn[MAX];
vector<int> adj[MAX];
stack<P> S;
vector<vector<P>> bcc;
 
int DFS(int curr, int prev = -1){
    // 이 정점에 dfsn 부여
    // result는 DFS 트리상에서 트리, 역방향 간선으로 도달 가능한 최소의 dfsn
    int result = dfsn[curr] = ++dcnt;
 
    // 인접한 정점 순회
    for(int next: adj[curr]){
        // DFS 트리상에서 자신의 부모면 스킵
        if(next == prev) continue;
 
        // 아직 방문하지 않은 간선이면 스택에 간선 (curr, next)을 넣음
        if(dfsn[curr] > dfsn[next]) S.push(P(curr, next));
        // 역방향 간선
        if(dfsn[next] > 0) result = min(result, dfsn[next]);
        // 트리 간선
        else{
            // DFS로 이어서 탐색
            int temp = DFS(next, curr);
            result = min(result, temp);
            // next가 DFS 트리상에서 curr의 조상 노드로 갈 수 없음: 새 BCC 발견
            if(temp >= dfsn[curr]){
                // 여태 스택에 쌓여있던 간선을 빼서 BCC 구성
                // 이때, 간선 (curr, next)까지만 빼내야 함
                vector<P> currBCC;
                while(!S.empty() && S.top() != P(curr, next)){
                    currBCC.push_back(S.top());
                    S.pop();
                }
                currBCC.push_back(S.top());
                S.pop();
                bcc.push_back(currBCC);
            }
        }
    }
 
    // 최소 도달 가능 dfsn을 리턴
    return result;
}

```

SCC에서는 해당 노드에서 자식을을 탐색하면서 가장 최소 방문 값을 찾고
자식들을 찾고 난 뒤의 SCC그룹 찾는 방식이지만

BCC에서는 자식들을 탐색하는 "중" 에 자식 노드가 Tree상 현재 탐색중인 노드의 조상 노드로 갈 수가 없는 경우 (즉 방문순서가 현재 탐색 노드보다 무조건 클 경우) 에서 BCC 추출

### 주의
해당 DFS Spanning Tree에서 Leaf Node는 무조건 __단절점이 아니다__  
DFS Tree의 root node의 child가 두 개 이상이라면, root node는 Cut Vertex이다.


### 단절점 찾는 알고리즘
해당 주의사항을 제외한 나머지 모든 노드들에 대해서  
해당 노드(v) 들의 자식 노드들(ch)이 v의 조상 노드로 향하는 역방향 간선을 가지지 않으면  
해당 V는 단절점이 되는 방식을 이용함  

즉 특정 A번 정점에서 자식 노드들이 정점 A를 거치지 않고 정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점  
그리고 이러한 코드는 dfs(node, pnode)꼴에서 해당 자식들 중 pnode는 스킵하는 방식으로 구현이 가능함

```c++
//해당 문제는 백준 11266 단절점 문제 푸는 코드
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_V 10001
int v, e;
vector<int> gh[MAX_V];
int dfsn[MAX_V];
int cnt = 0;

vector<int> curVetex;

int dfs(int node, int pnode = -1) {
    //방문순서 갱신
    int res = dfsn[node] = ++cnt; //방문순서 등록
    //res의미 : DFS 트리상에서 트리, 역방향 간선으로 도달 가능한 최소의 dfsn
    
    int childcnt = 0; //DFS Spanning Tree상 자식갯수
    bool isCurVertex = false; //

    for (int child : gh[node]) {
        if (child == pnode) continue;
        if (dfsn[child]) { // BackEdge 존재한다는 의미로 현재 노드에서 가장 높은 (값은 작은) 값 갱신
            res = min(res, dfsn[child]);
        }
        else {
            //트리 간선 영억. 리프 노드가 실행 할 곳은 안ㄷ됨
            childcnt++;
            int prev = dfs(child, node); // 다음 자식에 대한 자식들이 갈 수 있는 가장 높은 위치(방문순서 작은) 값 가져오기
            //만약 해당 자식이 갈 수 있는 높은 곳이 높아봤자 현재 노드인 경우 해당 노드는 단절점. 단 루트는 예외처리
            if (pnode != -1 && prev >= res) isCurVertex = true;
            //만약 어떤 자식이 올라 갈 수 있는 위치가 더 높은(즉 더 먼저 방문했는) 것이 존재할 경우 현재 노드도 그 위치에 갈 수 있다는 것이니 갱신
            res = min(prev, res);
        }
    }
    //DFS Tree의 노드에 대한처리. 만약 루트 노드에 대해서 자식이 2개이상이면 무조건 루트 노드도 단절점임
    if (pnode == -1 && childcnt >=2) isCurVertex =true;
    if (isCurVertex) curVetex.push_back(node);// 단절점에 대한 값 추가
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int a, b; cin >> a >> b;
        gh[a].push_back(b);
        gh[b].push_back(a);
    }
    for (int i = 1; i <= v; ++i) {
        if (dfsn[i] == 0) dfs(i);
    }
    cout << curVetex.size() <<'\n';
    sort(curVetex.begin(), curVetex.end());
    for (int &nd : curVetex) {
        cout << nd <<' ';
    }
    return 0;
}

```
### 단절선
단절선은 단절점과 동이한 방식이나, 차이점은 각 해당 v 노드에서 DST상 child들에 대해서
해당 child들이 올라 갈 수 있는 조상이 v보다 작으면 (방문순서상은 v보다 "초과"된 값) 해당 edge는 단절선이 됨  

또한 단절선에 대한 처리에선, 루트노드나 자식에 대한 고려가 필요x
그리고 (prev != -1 && result >= dfsn[nxt]) 에서 >=가 아닌 > 임에 주의

```c++
int DFS(int curr, int prev = -1){
    int result = dfsn[curr] = ++dcnt;

    for (int nxt : adj[curr]) {
        if (nxt == prev) continue;
        if (dfsn[nxt]) {  //역방향 간선 고려
            result = min(result, dfsn[nxt]);
        }
        else {
            //트리 간선
            int res = min(result, DFS(nxt, curr));
            if (res> result) {
                cutEdge.pushback((curr, nxt));
            }
            result = min(result, res);
        }
    }
    // 최소 도달 가능 dfsn을 리턴
    return result;
}

```



## SCC . BCC 결국 본질적으론 비슷

BCC 와 SCC는 거의 동일한 알고리즘이라 해도 무방  
다만 SCC는 유향 그래프에서 동작하는 것이고, 순방향 간선을 무시하는 형태  
BCC는 무향 그래프에서 동작하면, 무향 그래프이기에 순방향 간선이 의미가 없을 뿐더러  
취급한다고 해도 SCC와 동일하게 순방향 간선을 무시  

다만 BCC는 무향 그래프 이므로, 자식 노드를 탐색하는데  
DFS Spanning Tree상태를 약간은 고려하면서 다음 자식들에 대해서만 재귀적으로 접근하고  
해당 트리 간선 에 대한 처리를 끝나자마자 BCC탐색을 처리
