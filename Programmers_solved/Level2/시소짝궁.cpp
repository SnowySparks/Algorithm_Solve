#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//x1 ,x2 , 1/2 , 2/3, 3/2, 4/3, 3/4
int m[7] = {1,2,1,2,3,4,3};
int d[7] = {1,1,2,3,2,3,4};

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int,long long> wt;
    for (int i = 0 ; i < weights.size();i++) {
        for (int k = 0 ; k < 7 ; k ++) {
            int p = weights[i]*m[k];
            if (p%d[k]!=0) continue;
            p/=d[k];
            if (wt.find(p)!=wt.end()) {
                answer+=wt[p];
            }
        }
        wt[weights[i]]++;
    }
    return answer;
}