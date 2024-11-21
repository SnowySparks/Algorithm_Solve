#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    long long G;
    long long a=1, b=1;// 항상 a>=b
    vector<long long> answer;
    cin >> G;

    while (true) {
        if (b > (G-1)/2) break;
        if (a*a - b*b < G) {
            a++;
        }
        else if (a*a - b*b> G) {
            b++;
        }
        else {
            answer.push_back(a);
            a++;  
        }
    }
    if (answer.size() == 0) {
        cout << -1;
    }
    else {
        for (auto e : answer) {
            cout << e <<'\n';
        }
    }
    return 0;
}