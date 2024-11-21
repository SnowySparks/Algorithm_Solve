#include <iostream>
#include <vector>
#include <algorithm>
#define f(a,b,c) for(int a=b;a<c;a++)
const int inf = 1E5+1;
using namespace std;

int a[inf], b[inf], r[inf];

int lcs(int start, int end) {
    vector<int> lst;
    f(i,start,end+1) {
        if (lst.empty() || lst.back() < a[b[i]]) lst.push_back(a[b[i]]);
        else {
            vector<int>::iterator it = lower_bound(lst.begin(),lst.end(),a[b[i]]);
            *it = a[b[i]];
        }
    }
    return lst.size();
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N ; cin >> N;
    f(i,1,N+1) {int x; cin >> x; a[x]=i;}; f(i,1,N+1) cin >> b[i];
    cout << lcs(1,N);
    return 0;
}