#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> getSuffixArray(const string &st) {
    int n = st.size();

    vector<int> sa(n), group(n);
    for(int i = 0; i < n; ++i) sa[i];
    for (int i = 0; i < n; i++) group[i] = st[i] - 'a' + 1;

    vector<int> cnt(max(n, 256) + 1, 0); // 아스키코드 최대값 포함 가능하게 선언
    vector<int> sorted(n);
    vector<int> nextGroup(n);

    bool finished = false;
    for (int t = 1; ; t <<= 1) {
        // second key : group[sa[i] + t] 기준 정렬
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++) ++cnt[(sa[i] + t < n) ? group[sa[i] + t] : 0];
        for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sorted[--cnt[(sa[i] + t < n) ? group[sa[i] + t] : 0]] = sa[i];

        // first key : group[sa[i]] 기준 정렬
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++) ++cnt[group[sorted[i]]];
        for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--cnt[group[sorted[i]]]] = sorted[i];

        if (finished) break;

        nextGroup[sa[0]] = 1;
        for (int i = 1; i < n; i++) nextGroup[sa[i]] = nextGroup[sa[i - 1]] +  (group[sa[i - 1]] != group[sa[i]] || group[sa[i - 1] + t] != group[sa[i] + t]);
        group = nextGroup;
        
        finished = (group[sa.back()] == n);
    }

    return sa;
}

vector<int> getLCPArray(const string &st, const vector<int> &sa) {
    int n = st.size();
    vector<int> pos(n), lcp(n);

    for (int i = 0; i < n; i++) pos[sa[i]] = i;

    for (int i = 0, h = 0; i < n; i++) if (pos[i]) {
        int prev = sa[pos[i] - 1];
        while (st[prev + h] == st[i + h]) ++h;
        // int idx = pos[i];
        // while (st[sa[idx - 1] + h] == st[sa[idx] + h]) ++h;
        lcp[pos[i]] = h;
        if (h) --h;
    }

    return lcp;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    string st;
    cin >> st;

    auto sa = getSuffixArray(st);
    auto lcp = getLCPArray(st, sa);

    for (auto &e : sa) cout << e + 1 << " ";
    cout << "\nx ";
    for (int i = 1; i < lcp.size(); i++) cout << lcp[i] << " ";

    return 0;
}