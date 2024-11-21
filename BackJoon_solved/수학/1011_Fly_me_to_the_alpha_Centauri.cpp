#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    long long inp1,inp2;
    long long levels; //maximum speed , 2^levels = minimun length 
    //2*levels - 1 : 이동거리
    long long left;

    while(N--) {
        cin >> inp1 >> inp2;
        levels = 0;
        while (levels*levels <= (inp2 - inp1)) {
            levels++;
        }
        levels--;
        left = inp2-inp1 - (levels*levels);
        left = (long long) ceil (((double) left) / (double) levels);
        cout << 2*levels -1 + left <<'\n';
    }
    return 0;
}