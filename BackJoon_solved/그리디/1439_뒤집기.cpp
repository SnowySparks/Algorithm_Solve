#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string inp ; cin >> inp;

    int zero_to_one = 0;
    int one_to_zero = 0;
    int length = inp.size();
    
    if (inp[0]=='0') zero_to_one++;
    else one_to_zero++;
    
    for (int i = 0 ; i < length -1 ; i++) {
        if (inp[i]!=inp[i+1]) {
            if (inp[i+1] == '1') one_to_zero++;
            else zero_to_one++;
        }
    }
    cout << min(zero_to_one, one_to_zero);
    return 0;
}