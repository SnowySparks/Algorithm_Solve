#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

pair<double, double> datas[101]; // i 노드
int parent[101];
vector<pair<double, pair<int ,int> > > sv;

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
void _union(int a, int b) {
    int pa = find(a); int pb = find(b);
    if (pa == pb) return;
    parent[max(pa, pb)] = min(pa, pb);
}
double ln(double x1, double y1, double x2, double y2) {
    return sqrt( pow(abs(x1-x2),2) + pow(abs(y1-y2),2));
}
double ln (const pair<double, double> &a, const pair<double, double> &b) {
    return ln(a.first, a.second, b.first, b.second);
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i = 1; i <=N; i++) {
        cin >> datas[i].first >> datas[i].second; parent[i] = i;}

    for (int i = 1; i <= N-1; i++) {
        for (int j = i+1; j <= N; j++) {
            sv.push_back( { ln(datas[i], datas[j]) , {i,j}} );
        }
    } 
    sort(sv.begin(), sv.end());
    double answer = 0;
    for (auto e : sv) {
        if (find(e.second.first) != find(e.second.second)) {
            _union(e.second.first, e.second.second);
            answer += e.first;
        }
    }
    cout << answer;
    return 0;

}