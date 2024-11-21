#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

string tobinary(long long n) {
    string answer = "";
    stack<char> st;
    while (n > 0) {
        if (n % 2 == 1) {
            st.push('1');
        }
        else {
            st.push('0');
        }
        n/=2;
    }
    while(!st.empty()) {
        answer.push_back(st.top()); st.pop();
    }
    return answer;
}

bool isp = true;
char check(int start, int end, const string &binary) {
    if (!isp) return '*'; //즉각종료
    if (start == end ) return binary[start];
    int mid = (start + end) /2;
    char left = check(start, mid-1, binary);
    if (binary[mid] == '0' && left != '0') {isp = false; return '*';}
    char right = check(mid+1, end, binary);
    if (binary[mid] == '0' && right != '0') {isp = false; return '*';}

    if (binary[mid] == '0' && left =='0' && right == '0') {return '0';};
    return '1';
}
// 1 2 4 8 
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto e : numbers) {
        string binary = tobinary(e);
        int high = log2(binary.size()); //높이 -1 111 -> 높이값 1 , 실제높이 2
        long long total_node = (1 << (high +1)) -1;
        total_node -= binary.size();
        while(total_node--)  {
            binary = "0"+binary;
        }
        isp = true;
        check(0,binary.size()-1,binary);
        if (isp) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}