#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    unordered_map<string, string> dats;
    string inp1, inp2;
    while(N--) {
        cin >> inp1 >> inp2;
        dats[inp1] = inp2;
    }
    while(M--) {
        cin >> inp1;
        cout << dats[inp1] <<'\n';
    }
    return 0;
}