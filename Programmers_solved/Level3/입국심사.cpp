#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start = 1 ; long long end =  1E15*4;
    long long cnt = 0;

    while(start <= end) {
        cnt = 0;
        long long mid = (start + end)/2;
        for (auto e : times) {
            cnt+= (mid/e);
            if (cnt > n) break;
        }

        if (cnt < n) start = mid +1;
        else {
            answer = mid;
            end= mid - 1;
        }
    }
    return answer;
}