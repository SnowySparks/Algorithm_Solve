#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> rain_dt; //각각의 우박수 값 저장
    vector<double> dp_sum;
    dp_sum.push_back(0); // x= 구간이 오직 0 하나일때에 대한데이터 저장
    rain_dt.push_back(k);
    int loc = 0;
    while (k != 1) {
        if (k %2 == 0) k=k/2;
        else k=k*3+1;
        loc++;
        
        rain_dt.push_back(k);
        dp_sum.push_back ( (double) (rain_dt[loc] + rain_dt[loc-1])/2 + dp_sum[loc-1]);
    }
    
    int length = rain_dt.size()-1; //마지막 인덱스 위치
    
    for (auto e : ranges) {
        if (length + e[1] >= e[0]) {
        answer.push_back( dp_sum[length + e[1]] - dp_sum[e[0]]); }
        else {
            answer.push_back(-1);
        }
    }
    return answer;
}