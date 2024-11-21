#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n;

bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[n] == b[n]) return a[0] > b[0];
    return a[n] < b[n];
}

int mod_sum(const vector<int>& a, int d) {
    int sum = 0;
    for (int p : a) {
        sum += p%d;
    } return sum;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    n = col-1;
    sort(data.begin(), data.end(), comp);
    vector<int> dts;
    for (int i = row_begin-1; i < row_end; i++) {
        dts.push_back(mod_sum(data[i],i+1));
    }
    answer = dts[0];
    for (int i = 1 ; i < dts.size(); i++) {
        answer^= dts[i];
    }

    return answer;
}