#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,temp;
    cin >> n;

    int two=0,five=0;

    for (int i=1 ; i<= n ;i++) {
        temp = i;

        while (temp%5 == 0) {
            temp=temp/5 ;
            five++;
        }
        while (temp%2==0) {
            temp=temp/2;
            two++;
        }
    }

    cout << min (five, two);

    return 0;
}