#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;

struct city {
    int x, y, rx, ry;
    city(int x = 0, int y = 0) : x(x), y(y), rx(0), ry(0) {}
    city(int x, int y, int rx, int ry) : x(x), y(y), rx(rx), ry(ry) {}

    void cal_degree(const city &pts) { //px py 기준 
        rx = x - pts.x; ry = y - pts.y;
    }

    bool operator<(const city &a) const {
        if ((1LL * ry * a.rx) != (1LL * rx * a.ry)) return (1LL * ry * a.rx) < (1LL * rx * a.ry);
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
};

const int max_n = 2e5+1;
city arr[max_n];
vector<city> lst(max_n);

long long ccw(const city &a, const city &b, const city &c) { //벡터ab, 벡터ac 외적곱.
    return 1LL*(b.x - a.x)*(c.y-a.y) - 1LL*(c.x-a.x)*(b.y-a.y);
}

long long ccw(ll bx, ll by, ll cx, ll cy) {
    return bx*cy - cx*by;
}

long long ccw(const city &a, const city &b, const city &c, const city &d) { //벡터ab, 벡터cd ccw 판단
    long long abx = b.x- a.x, aby = b.y -a.y;
    long long cdx = d.x- c.x, cdy = d.y -c.y;
    return abx*cdy - aby*cdx;
}

long long dist(const city &a, const city &b) { // 두 점 거리 : 실제 city struct 가지고
    return 1LL*(a.x - b.x)*(a.x - b.x) + 1LL*(a.y - b.y)*(a.y - b.y);
}

long long dist(int aidx, int bidx) { // convex hull 좌표 전용 인덱스로 두 점 거리 구하기
    return dist(lst[aidx],lst[bidx]);
}
ㅏ

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    int n;
    vector<city> lst(n);
    while (T--)
    {
        // Input
        cin >> n;
        lst.clear();

        // 기준점 찾으면서 좌표 입력
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].x >> arr[i].y;
            if (i >= 1 && arr[i] < arr[0]) swap(arr[0], arr[i]);
        }

        // 기준점 기준 계슨 (tan기울기)
        for (int i = 1; i < n; ++i) {
            arr[i].cal_degree(arr[0]);
        }

        // 기준점 제외 정렬
        sort(arr+1, arr+n);

        // Convex_Hull 시행
        lst.push_back(arr[0]); lst.push_back(arr[1]);

        for (int i = 2; i < n; ++i) {
            while ((int)lst.size() >= 2)
            {
                int l = (int)lst.size();
                if (ccw(lst[l-2],lst[l-1],arr[i]) > 0) {
                    break;
                }
                lst.pop_back();
            }
            lst.push_back(arr[i]);
        }

        // 회전하는 캘리퍼스 - 볼록 다각형에 완전히 포함하는 가장 긴 선분의 길이를 구하는 용도 O(N) - 즉 가장 멀리 있는 두 점 
        // 전제 조건 : Convex Hull 연산 결과의 점들 - 정확힌 그라함의 알고리즘으로 구한 (순서 바뀌면 안됨)

        // 1. 초기 : A점을 0번, C점을 1번으로두기 
        // 2. A다음 점을 B, C 다음 점은 D 라고 두기. 그리고 초기 답 =  AC의 길이

        // 
        // 3. AB 와 CD 벡터를 CCW곱 (외적)을 하고 이 AB, CD 벡터가 가능한 멀어지도록 두기 (반시계, 양수 이면 C를 이동/ 시계 음수이면 A를 이동)
        // 이때 이동후 AC 길이 갱신
        // 4. A가 원래 위치에 도달하면 그 즉시 종료
        // 아닌경우 2~3을 계속 반복함

        // 편의상 A를 한칸 이동하면서 C를 최대한 이동하는 방식이 유명


        city ans1, ans2; //정답 위치
        int j = 1, j_nxt; 
        int sz = lst.size();
        long long max_length = -1;

        for (int i = 0; i < sz; ++i) {
            int i_nxt = (i+1)%sz;
            while (1)
            {
                j_nxt = (j+1)%sz;

            if (max_length < dist(lst[i],lst[j])) {
                max_length = dist(lst[i],lst[j]);
                ans1 = lst[i];
                ans2 = lst[j];
            }

                if (ccw(lst[i],lst[i_nxt],lst[j],lst[j_nxt]) > 0) j = j_nxt;
                else break;
            
            }
        }

        cout << ans1.x <<' ' << ans1.y << ' ' <<ans2.x <<' ' <<ans2.y <<'\n';
    }

    return 0;
}