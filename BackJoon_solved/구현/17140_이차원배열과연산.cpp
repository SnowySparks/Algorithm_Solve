#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
int target_r, target_c, k;

int R = 3, C = 3;
int arr[100][100];
int cnt[101];
vector<pair<int, int> > tmp;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> target_r >> target_c >> k; target_r--; target_c--;
    memset(arr, 0, sizeof(arr));
    f(i, 0, 3) f(j, 0, 3) cin >> arr[i][j];
    int t = 0;
    while (t <= 100)
    {

        if (arr[target_r][target_c] == k) break;
        t++;
        if (t > 100) break;
        int maxC = 0, maxR = 0;
        if (R >= C) {
            f(r, 0, R) {
                memset(cnt, 0, sizeof(cnt));
                tmp.clear();
                f(c, 0, C) {
                    if(arr[r][c]) cnt[arr[r][c]]++;
                }
                f(i, 1, 101) if (cnt[i]) tmp.push_back({i, cnt[i]});
                sort(tmp.begin(), tmp.end(), [](const pair<int ,int> &a, const pair<int ,int> &b){
                    if (a.second == b.second) return a.first < b.first;
                    return a.second < b.second;
                });
                memset(arr[r], 0, sizeof(arr[r]));
                maxC = max(maxC, min((int)tmp.size()*2, 100));
                f(i, 0, min(50, (int)tmp.size())) {
                    arr[r][2*i] = tmp[i].first;
                    arr[r][2*i+1] = tmp[i].second;
                }
            }
            C = maxC;
            // cout << "======" << t << "===\n";
            // f(i, 0, R) {
            //     f(j, 0, C) {
            //         cout << arr[i][j] <<' ';
            //     }
            //     cout << '\n';
            // }
        }
        else {
            f(c, 0, C) {
                memset(cnt, 0, sizeof(cnt));
                tmp.clear();
                f(r, 0, R) {
                    if(arr[r][c]) cnt[arr[r][c]]++;
                }
                f(i, 1, 101) if (cnt[i]) tmp.push_back({i, cnt[i]});
                sort(tmp.begin(), tmp.end(), [](const pair<int ,int> &a, const pair<int ,int> &b){
                    if (a.second == b.second) return a.first < b.first;
                    return a.second < b.second;
                });
                f(r, 0, R) arr[r][c] = 0;
                maxR = max(maxR, min((int)tmp.size()*2, 100));
                f(i, 0, min(50, (int)tmp.size())) {
                    arr[2*i][c] = tmp[i].first;
                    arr[2*i+1][c] = tmp[i].second;
                }
            }
            R = maxR;
            // cout << "======" << t << "===\n";
            // f(i, 0, R) {
            //     f(j, 0, C) {
            //         cout << arr[i][j] <<' ';
            //     }
            //     cout << '\n';
            // }
        }
    }
    cout << (t > 100 ? -1 : t);
    return 0;
}