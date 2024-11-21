#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define M_M 10000
using namespace std;
int num_count[10]; //끝나는 가장 먼 위치 각 숫자마다
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int temp;
    int answer = 0;
    vector<int> co(N); //command
    vector<int> box;
    for (int i = 0 ; i < 10 ; i++) {
        num_count[i] = -1;
    }
    for (int i = 0 ; i < N ; i++) {
        cin >> co[i];
        num_count[co[i]] = i;
    }
    int idx, cal_temp, max_temp;

    for (int i = 0 ; i < N ; i++) {
        if (find(box.begin(), box.end(),co[i]) == box.end()) {
            if (box.size()<4) {
                box.push_back(co[i]); answer++;
            }
            else {
                idx = -1 ; cal_temp = 0 ; max_temp =-1;
                for (int k = 0 ; k < 4 ; k++) {
                    cal_temp =(num_count[box[k]]) - i;
                    cal_temp = (cal_temp < 0) ? cal_temp*(-10000):cal_temp;
                    if (max_temp < cal_temp) {idx = k ; max_temp = cal_temp;}
                }
                box[idx] = co[i];
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}