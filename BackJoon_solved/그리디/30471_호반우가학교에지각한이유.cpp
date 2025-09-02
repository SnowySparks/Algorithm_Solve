#include <iostream>
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 1;
const int M = 3e5;
int n, m;
int group[N];
pii slot[M];
int slimeSize[N];
ll miniSlimeSize[N];

void init();
void solve();
int findGroup(int a);
bool isDisJoint(int a, int b);
void unite(int a, int b, ll &ans);


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    init();
    solve();

    return 0;
}

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
         group[i] = i;
         slimeSize[i] = 1;
    }
    for (int i = 0; i < m; ++i) cin >> slot[i].first >> slot[i].second;
}

void solve() {
    ll ans = n; // 가장 초기의 답.
    for (int i = 0; i < m; ++i) {
        int a = slot[i].first, b = slot[i].second;
        
        if (isDisJoint(a, b)) {
            unite(a, b, ans);
        }
        cout << ans << '\n';

    }
}

int findGroup(int a) {
    if (group[a] == a) return a;
    return group[a] = findGroup(group[a]);
}

bool isDisJoint(int a, int b) {
    a = findGroup(a);
    b = findGroup(b);
    return (a == b ? false : true);
}

void unite(int a, int b, ll &ans) {
    a = findGroup(a);
    b = findGroup(b);

    ans -= (miniSlimeSize[a] + miniSlimeSize[b]);


    int uniteSize = slimeSize[a] + slimeSize[b];
    ll madeMiniSlime = (1LL * uniteSize * (1LL * uniteSize - 1) ) / 2;
    ans += madeMiniSlime;

    miniSlimeSize[a] = miniSlimeSize[b] = madeMiniSlime;
    slimeSize[a] = slimeSize[b] = uniteSize;
    group[max(a, b)] = min(a, b);
}