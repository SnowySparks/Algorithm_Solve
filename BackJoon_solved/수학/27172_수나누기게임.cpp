#include <iostream>
using namespace std;
int score[1000001];
bool isIn[1000001];
int inp[100000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int maxVal = -1;
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
        isIn[inp[i]]=true;
        maxVal = max(maxVal, inp[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = inp[i]*2; j <= maxVal; j += inp[i]) {
            if (isIn[j]) {
                score[inp[i]]++;
                score[j]--;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << score[inp[i]] <<' ';
    }
    return 0;
}