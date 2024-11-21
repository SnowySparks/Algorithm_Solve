//https://programmers.co.kr/learn/courses/30/lessons/87390
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ans;
    for (long long i=left;i<=right;i++) {
        ans.push_back( (i%n)>(i/n)?(i%n)+1:(i/n)+1);
    }
    return ans;
    
}