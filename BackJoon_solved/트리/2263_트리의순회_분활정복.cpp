#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs (int inl, int inr, int pl, int pr, const vector<int> &in, const vector<int> &idx, const vector<int> &p) {
    //후위는 항상 가장 오른쪽에 루트값이 됨
    //서브루트와 이에 맞는 범위구간 안에서도 해당 서브 트리의 루트는 항상 그 구간의 오른쪽 맨끝
    if (inl > inr || pl > pr) return;
    int root_in_index = idx[p[pr]];
    int left_size = root_in_index - inl;
    cout << in[root_in_index] <<' ';
    dfs(inl,root_in_index-1,pl,pl+left_size -1,in,idx,p);
    dfs(root_in_index+1,inr,pl+left_size,pr-1,in,idx,p);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<int> inorder(N+1);
    vector<int> inorder_index(N+1);
    vector<int> postorder(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> inorder[i];
        inorder_index[ inorder[i] ] = i;
    }
    for (int i = 1; i <= N; i++) {
        cin >>postorder[i];
    }
    dfs(1,N,1,N,inorder,inorder_index,postorder);
    return 0;
}