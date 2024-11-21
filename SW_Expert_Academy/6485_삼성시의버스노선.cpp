#include <iostream>
#include <cstring>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;++a)

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T,n,fr,to,p,tmp,max_val; cin >> T;
    int arr[5003];
    f(t,1,T+1) {
        max_val = -1;
        cin >> n;
        f(i,0,n) {
            cin >> fr >> to;
            arr[fr]++;
            arr[to+1]--;
        }
        f(i,1,5001) arr[i]+=arr[i-1];
        cout << '#' << t;
        cin >> p;
        f(i,0,p) {
            cin >> tmp;
            cout<<' '<<arr[tmp];
        }
        cout<<'\n';
        memset(arr,0,sizeof(arr));
    }   
}
