#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a,b;
int ans = -2;

void bfs(long long value, int count) {
    if (value > b) return;
    if (value == b) {
        ans = count;
        return;
    }
    bfs(value*2,count+1);
    bfs(value*10+1,count+1);
}

int main(void) {
    cin >> a >> b;
    bfs(a,0);
    cout << ans+1;
    return 0;
}