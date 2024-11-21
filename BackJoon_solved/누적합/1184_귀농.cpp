#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int srt[51][51];
int sum[51][51];

int area(int r1, int c1, int r2, int c2) {
    return sum[max(r2,r1)][max(c2,c1)] - sum[min(r1,r2)-1][max(c2,c1)] - sum[max(r2,r1)][min(c2,c1)-1] + sum[min(r1,r2)-1][min(c2,c1)-1];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long answer= 0;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> srt[i][j];
            if (i==1 && j==1) sum[i][j] = srt[i][j];
            else sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + srt[i][j];
        }
    }

    unordered_map<int, int> sum_table;
    int temp;
    
    for (int i = 1 ; i <N; i++) {
        for (int j = 1 ; j < N; j++) {
            for (int k = 1 ; k <= i ; k++) {
                for (int p = 1; p<= j ; p++) {
                    temp=area(k,p,i,j);
                    if (sum_table.find(temp)!=sum_table.end()) sum_table[temp]++;
                    else sum_table[temp]=1;
                }
            }
            //오른쪽 하단 (i+1,j+1) ~ (k,p)
            for (int k = i+1; k <= N ; k++) {
                for (int p = j+1; p<= N ; p++) {
                    temp = area(i+1,j+1,k,p);
                    if (sum_table.find(temp)!=sum_table.end()) answer+=sum_table[temp];
                }
            }
            sum_table.clear();
        }
    }
    //꼭짓점 위치 : y=x방향, 위오른쪽 상자 꼭짓점을 (i,j)로 둠
    for (int i = 1; i<N; i++) {
        for (int j = N; j>1 ; j--) {
            //오른쪽 상단 (i,j) ~ (k,p까지); k = i ~ 1, p = j ~ N
            for (int k = i ; k >= 1; k--) {
                for (int p = j; p<= N ; p++) {
                    temp = area(i,j,k,p);
                    if (sum_table.find(temp)==sum_table.end()) sum_table[temp]=1;
                    else sum_table[temp]++;
                }
            }
            //왼쪽 하단 (i+1, j-1) ~ (k,p) ; k= i+1 ~ N, p: j-1 ~ 1
            for (int k = i+1; k <= N ; k++) {
                for (int p = j-1 ; p>= 1 ; p--) {
                    temp = area(i+1,j-1,k,p);
                    if (sum_table.find(temp)!=sum_table.end()) {answer+=sum_table[temp];
                    }
                }
            }
            sum_table.clear();
        }
    }
    
    cout << answer; return 0;
}