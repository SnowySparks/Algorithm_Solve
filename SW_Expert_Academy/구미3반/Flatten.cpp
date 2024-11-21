#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int main(void) {
    //freopen("input.txt", "r", stdin);
    int n,k,dump,tmp,max_val,min_val; 
    int cnt[101];
    for (int t = 1; t <= 10; ++t) {
        memset(cnt,0,sizeof(cnt)); max_val=-1;min_val=1001;
        cin >> dump;
        for (int i = 0 ; i < 100 ; ++i) {
            cin >> tmp; 
            ++cnt[tmp];
            min_val = min(min_val,tmp);
            max_val = max(max_val,tmp);
        }
        while( min_val < max_val)
        {   
            int diff = min(dump,min(cnt[max_val],cnt[min_val]));
            cnt[max_val-1]+=diff;
            cnt[min_val+1]+=diff;
            cnt[max_val]-=diff;
            cnt[min_val]-=diff;
            dump -= diff;
            if (cnt[max_val] == 0) --max_val;
            if (cnt[min_val] == 0) ++min_val;

            if (dump==0) break;
        }
        
        cout <<'#' << t <<' ' <<(max_val - min_val)<<'\n';
    }

    return 0;
}