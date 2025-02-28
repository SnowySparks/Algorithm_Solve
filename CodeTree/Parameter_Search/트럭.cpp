#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n, m;
struct info {
    int guest, s, p; //손님번호, 최소크기, 구매가격
    info(int guest,int s,int p) : guest(guest), s(s), p(p) {}
    bool operator<(const info &other) const  {
        return s < other.s;
    }
    bool operator>(const info &other) const {
        return s > other.s;
    }
};
vector<info> lst;
vector<ll> preFix;
int maxPay[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    // --- input
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        for (int j = 0; j < a; ++j) {
            int s, p; cin >> s >> p;
            lst.emplace_back(i,s,p);
        }
    }
    // cout << lst.size() << '\n';
    // 차량 크기 순 정렬
    sort(lst.begin(), lst.end(), [](const info &a, const info &b){
        if (a.s == b.s) return a.p > b.p;
        return a.s < b.s;
    });

    // 누적합. 단 기존 차량 페이보다 더 좋은 경우가 있을 경우에 한해서만
    preFix.resize(lst.size());
    preFix[0] = lst[0].p;
    maxPay[lst[0].guest] = lst[0].p;

    for (int i = 1; i < lst.size(); ++i) {
        int guest = lst[i].guest;
        int s = lst[i].s;
        int p = lst[i].p;
        preFix[i] = preFix[i-1];

        // 아직 등록 안한 상태
        if (maxPay[guest] == 0) {
            preFix[i] += p;
            maxPay[guest] = p;
        }
        // 동일 손님 -> 더 좋은 페이가 나올 때
        else if (maxPay[guest] > 0 && maxPay[guest] < p) {
            preFix[i]+= (p - maxPay[guest]);
            maxPay[guest] = p;
        }
        // 더 안좋은 페이 -> 무시
    }
    // for (int i = 0; i < preFix.size(); ++i) {
    //     cout << "idx : " << i << "-> " << preFix[i] << '\n';
    // }
    cin >> m;
    int minEarn;
    for (int i = 0; i < m; ++i) {
        cin >> minEarn;
        // 절대 안됨 ->어떻게 하든 수익 조건 안됨
        if (minEarn > preFix.back()) {
            cout << -1 <<' ';
            continue;
        }
        // 차량 무게에 대한 매개변수탐색
        int l = lst.front().s, r = lst.back().s;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int loc = upper_bound(lst.begin(), lst.end(), mid, [](const int v, const info &d){
                return v < d.s;
            }) - lst.begin();
            loc--;
            if (loc == -1) {
                l = mid + 1;
                continue;
            }
            if (preFix[loc] >= minEarn) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << ' ';
    }

    return 0;
}