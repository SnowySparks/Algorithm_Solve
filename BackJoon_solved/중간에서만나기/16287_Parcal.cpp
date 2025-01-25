#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 
int w, n;
const int MAXCAL = 2e5 + 1;
int arr[5000];
int loc1[MAXCAL * 2];
int loc2[MAXCAL * 2];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> w >> n;
    memset(loc1, -1, sizeof(loc1));
    memset(loc2, -1, sizeof(loc2));
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int i = 0; i < n-1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cal = arr[i] + arr[j];
            if (loc1[cal] == -1 && loc2[cal] == -1) {
                loc1[cal] = i;
                loc2[cal] = j;
            }
        }
    }

    for (int i = 0; i < n-1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cal = w - (arr[i] + arr[j]);
            if (cal < 0 || cal > 400000) continue;
            if (loc1[cal] == -1 || loc2[cal] == -1) continue;
            if (loc1[cal] == i || loc1[cal] == j) continue;
            if (loc2[cal] == i || loc2[cal] == j) continue;
            cout << "YES";
            return 0; 
        }
    }
    
    cout << "NO";
    return 0;
}