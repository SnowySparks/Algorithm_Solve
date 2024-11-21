#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctype.h>

using namespace std;

vector<string> to_set(const string& value) {
    vector<string> result;
    for (int i = 0; i < value.length()-1; i++) {
        if (isalpha(value[i]) && isalpha(value[i+1])) {
            result.push_back(value.substr(i,2));
        }
    }
    return result; 
}
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) { return  a > b ? a : b; }

void min_max(int a, int b , int &inp1, int &inp2) {
    inp1+=min(a,b);
    inp2+=max(a,b);
}

int solution(string str1, string str2) {
    for (char &a : str1) {
        a=tolower(a);
    }

    for (char &b : str2) {
        b=tolower(b);
    }

    vector<string> a1 = to_set(str1), a2=to_set(str2);
    set<string> united;

    for (auto e : a1) {
        united.insert(e);
    }
    for (auto e :a2) {
        united.insert(e);
    }
    int n=0;
    int m=0;

    for (auto e : united) {
        min_max(count(a1.begin(),a1.end(),e),count(a2.begin(),a2.end(),e),n,m);
    }

   double ap = (double )n/(double)m;
   int answer= ap * (double) 65536;

    return (n==m)?65536 : answer;
    
}