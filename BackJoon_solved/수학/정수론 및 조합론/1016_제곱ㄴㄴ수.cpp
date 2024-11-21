#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isno [1000001];
//0 : min , max-min -1 :

// 소수의 제곱으로 나뉘어지는지를 판단하면 됨.

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long min, max;
    long long ans=0, temp;
    cin >> min >> max;

    //아리스토테네스 체
    for (long long i = 2 ; i*i <= max ; i++) {
        temp = min / (i*i);


        if (min % (i*i) != 0) temp++; //min은 현재 i*i 으로는 안나뉘어지니
        //최소 몫의 값을 하나 더 늘림

        //temp * i * 1 는 무조건 제곱 ㄴㄴ 수가 아니므로 표시
        //몫의 값을 계속 늘리면서 판단.
        while (temp * i* i <= max) {
            isno[temp*i*i-min] = true;
            temp++;
        }
    }
    for (int i = 0 ; i <= max-min ;i++) {
        if (!isno[i]) ans++;
    }
    cout << ans;
    return 0;


}