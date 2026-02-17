#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100'001;
int n;
int leftChild[N];
int rightChild[N];

int totalCnt = 1;
int mvCnt = 0;
bool isOver = false;
int endNode = -1;

void midorder(int node) {
    if (leftChild[node] != -1) midorder(leftChild[node]);
    endNode = node;
    if (rightChild[node] != -1) midorder(rightChild[node]);
}

void dfs(int node) {
    if (leftChild[node] != -1) {
        mvCnt++;
        dfs(leftChild[node]);

        if (!isOver) mvCnt++;
    }

    if (rightChild[node] != -1) {
        mvCnt++;
        dfs(rightChild[node]);
        if (!isOver) ++mvCnt;
    }

    if (node == endNode) {
        isOver = true;
        return;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        cin >> leftChild[a] >> rightChild[a];
    }
    midorder(1);
    dfs(1);
    cout << mvCnt;
    return 0;
}