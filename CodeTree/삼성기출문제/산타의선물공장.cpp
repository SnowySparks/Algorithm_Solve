#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int Q, n, m;
bool breaken[11];
// Union-Find
int p[11];
int findp(int x) {
    if (p[x] == x) return x;
    return p[x] = findp(p[x]);
}
bool isSameParent(int a, int b) {
    return findp(a) == findp(b);
}
void unite(int from, int to) {
    from = findp(from);
    to = findp(to);
    p[from] = to;
}
// 노드정의
struct Node { // box : id, 무게, 원래 벨트 위치
    int id, w, belt;
    Node *prev = nullptr;
    Node *next = nullptr;
    Node(int id = 0, int w = 0, int belt = 0) : id(id), w(w), belt(belt), prev(nullptr), next(nullptr) {}
    void clear() {
        prev = nullptr;
        next = nullptr;
    }
};
// 죄우연결
void connectNode(Node *l, Node *r) {
    l->next = r;
    r->prev = l;
}
// 좌, 중간, 우 연결
void connectBetween(Node *l, Node *mid, Node *r) {
    connectNode(l, mid);
    connectNode(mid, r);
}

unordered_map<int, Node*> hashNode;

class List{
    public:
    Node head,tail;

    List() {
        connectNode(&head, &tail);
    }
    bool empty() {
        return head.next == &tail;
    }
    void clear() {
        connectNode(&head, &tail);
    }
    void push(Node *newNode) {
        connectBetween(tail.prev, newNode, &tail);
    }
    void erase(Node *node) {
        connectNode(node->prev, node->next);
    }
    Node *front() {
        if (empty()) return nullptr;
        return head.next;
        
    }
    Node* pop() {
        if (empty()) return nullptr;
        Node *target = head.next;
        connectNode(&head, target->next);
        target->clear();
        return target;
    }
    void dragNode(Node *target) {
        Node *headNode = head.next;
        if (target==headNode) return; //이미 가장 앞이다 -> 그대로 끝
        Node *targetFront = target->prev;
        Node *tailNode = tail.prev;
        connectNode(&head, target);
        connectNode(tailNode,headNode);
        connectNode(targetFront, &tail);
    }

    void connectOtherLine(List &other) {
        connectNode(tail.prev, other.head.next);
        connectNode(other.tail.prev, &tail);
        other.clear();
    }

    void print() {
        Node *node = head.next;
        while (node != &tail) {
            cout << node->id << "->";
            node = node->next;
        }
    }
};

Node box[100001];
List Line[11];

void init() {
    cin >> n >> m;
    int cntLine = n/m;
    for (int i = 1; i <= m; ++i) p[i] = i;
    for (int i = 1; i <= n; ++i) {
        cin >> box[i].id;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> box[i].w;
    }
    for (int i = 1; i <= n; ++i) {
        int lineNum = (i-1)/cntLine + 1;
        box[i].belt = lineNum;
        hashNode[box[i].id] = &box[i];
        Line[lineNum].push(&(box[i]));
    }
}

long long outBoxes(int w_max) {
    long long res = 0;
    for (int i = 1; i <= m; ++i) {
        if (breaken[i]) continue;
        if (Line[i].empty()) continue;
        int frontWeight = Line[i].front()->w;
        // cout << "outBox" << i << ' ' << frontWeight << '\n';
        if (frontWeight <= w_max) {
            res += frontWeight;
            hashNode.erase(Line[i].front()->id);
            Line[i].pop();
        }
        else {
            Line[i].push(Line[i].pop());
        }
    }
    return res;
}

int removeBox(int r_id) {
    if (hashNode.find(r_id) == hashNode.end()) return -1;
    Node *target = hashNode[r_id];
    hashNode.erase(r_id);
    connectNode(target->prev, target->next);
    target->clear();
    return r_id;
}

int findBox(int f_id) {
    if (hashNode.find(f_id) == hashNode.end()) return -1;
    Node *target = hashNode[f_id];
    Line[findp(target->belt)].dragNode(target);
    return findp(target->belt);
}

int breakBelt(int b_num) {
    if (breaken[b_num]) return -1;
    breaken[b_num] = true;

    int targetBelt = 0;
    for (int i = 1; i < m; ++i) {
        int searchBelt = (b_num - 1 + i)%m + 1;
        if (!breaken[searchBelt]) {
            targetBelt = searchBelt;
            unite(b_num, targetBelt);
            break;
        }
    }
    Line[targetBelt].connectOtherLine(Line[b_num]);
    return b_num;
}


using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("in.txt","r",stdin);
    cin >> Q;
    int w_max, r_id, f_id,b_num;
    for (int query = 1; query <= Q; ++query) {
        int cmd; cin >> cmd;
        switch (cmd)
        {
        case 100:
            init();
            break;
        case 200:
            cin >> w_max;
            cout << outBoxes(w_max) << '\n';
            break;
        case 300:
            cin >> r_id;
            cout << removeBox(r_id) << '\n';
            break;
        case 400:
            cin >> f_id;
            cout << findBox(f_id) << '\n';
            break;
        case 500:
            cin >> b_num;
            cout << breakBelt(b_num) << '\n';
        default:
            break;
        }
    }
    return 0;
}