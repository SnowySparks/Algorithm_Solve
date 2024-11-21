#include <iostream>
using namespace std;
const int MAX = 1e6;
int tree[MAX*3+3];

int q(int node, int s, int e, int val){
    if(s==e){
        cout<<s<<'\n';
        return s;
    }
    int mid = (s+e)/2;
    if(tree[node*2]<val) return q(2*node+1,mid+1,e,val-tree[node*2]);
    else return q(2*node,s,mid,val);
}

void update(int node, int s, int e, int idx, int diff){
    if(s > idx || e < idx) return;
    tree[node]+=diff;
    if(s!=e) {
        int mid = (s+e)/2;
        update(2*node,s,mid,idx,diff);
        update(2*node+1,mid+1,e,idx,diff); 
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int query,a,b,c;
    cin >> query;
    for(int i=0;i<query;i++){
        cin>>a>>b;
        if(a==1)update(1,1,MAX,q(1,1,MAX,b),-1);
        else{
            cin>>c;
            update(1,1,MAX,b,c);
        }
    }
    return 0;
}
