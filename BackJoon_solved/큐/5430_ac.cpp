#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int N,cnt,temp;
    string inp;
    bool error;
    string s,ans="";
    cin >> N;

    deque<int> que;

    bool istoleft = true;

    while (N--) {
        cin >> s >> cnt;
        error =false;
        istoleft=true;
        que.clear();
        ans.clear();

        cin >> inp;

        for (auto e : inp) {
            if (!isdigit(e)) {
                if (temp != 0) {
                    que.push_back(temp);
                }
                temp =0;
            }
            else {
                temp = temp *10 + (e - '0');
            }
        }

        for (auto e : s) {
            if (e=='R') {
                istoleft = (istoleft ? false : true);
            }
            else {
                if (que.empty()) {
                    cout << "error" <<'\n';
                    error =true;
                    break;
                }
                else {
                    if (istoleft) {
                        que.pop_front();
                    }
                    else {
                        que.pop_back();
                    }
                }
            }
        }

        if (!error) {
            cout << "[";
            if (istoleft) {
                for (auto ab = que.begin() ; ab != que.end() ; ab++) {
                    if (ab != que.end()-1 ) {
                        cout << *ab << ",";
                    }
                    else {
                        cout << *ab;
                    }
                }
            }
            else {
                for (auto ab = que.rbegin() ; ab != que.rend() ; ab++) {
                    if (ab != que.rend()-1) {
                        cout << *ab << ",";
                    }
                    else {
                        cout << *ab;
                    }
                }
            }
            cout << "]\n";
        }
    }

   
    return 0;
}