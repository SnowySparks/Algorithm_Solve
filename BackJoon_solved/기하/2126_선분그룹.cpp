#include <iostream>
using namespace std;
#define f(a,b,c) for (int a=b;a<=c;a++)

typedef struct _pt {
    int x,y;
    bool operator<(const struct _pt &b) const {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
    bool operator>(const struct _pt &b) const {
        if (x == b.x) return y > b.y;
        return x > b.x;
    }
    bool operator==(const struct _pt &b) {
        return (x==b.x)&&(y==b.y);
    }
    bool operator<=(const struct _pt &b) const {
        if (x == b.x) return y <= b.y;
        return x <= b.x;
    }
    bool operator>=(const struct _pt &b) const {
        if (x == b.x) return y >= b.y;
        return x >= b.x;
    }
} pt;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
}
int ccw(pt a, pt b, pt c) {
    return ccw(a.x, a.y, b.x, b.y, c.x, c.y);
}
int cw(pt a, pt b, pt c) {
    int r = ccw(a,b,c);
    return (r > 0) ? 1 : (r < 0 ? -1 : 0);
}

bool check_cross(pt a1, pt a2, pt b1, pt b2) {
    if (a1 > a2) swap(a1,a2);
    if (b1 > b2) swap(b1,b2);

    int c1 = cw(a1,a2,b1) * cw(a1,a2,b2);
    int c2 = cw(b1,b2,a1) * cw(b1,b2,a2);

    if (c1 == 0 && c2 == 0) {
        if (b1 <= a2 && a1 <= b2) return true;
        else return false;
    }
    else if (c1 <= 0 && c2 <= 0) return true;
    else return false;
}


int p[3001];
pair<pt ,pt> pts[3001];
int cntp[3001];
int n;

int parent(int loc) {
    if (p[loc] == loc) return loc;
    return p[loc]=parent(p[loc]);
}

bool _union(int a, int b) {
    int pa = parent(a), pb= parent(b);
    if (pa == pb) return false;
    p[max(pa,pb)] = min(pa,pb);
    cntp[min(pa,pb)] += cntp[max(pa,pb)];
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i,1,n) cin >> pts[i].first.x >> pts[i].first.y >> pts[i].second.x >> pts[i].second.y;
    f(i,1,n) {
        p[i] = i; cntp[i] = 1;
    }

    f(i,1,n) {
        f(k,i+1,n) {
            if (check_cross(pts[i].first,pts[i].second,pts[k].first,pts[k].second)) {
                _union(i,k);
            }
        }
    }

    int grupcnt = 0, sizegroup = -1;
    f(i,1,n) {
        if (parent(i) == i) {
            grupcnt++;
            if (sizegroup < cntp[i]) {
                sizegroup = cntp[i];
            }
        }
    }
    cout << grupcnt <<'\n' << sizegroup;
    return 0;
}