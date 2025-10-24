#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> split_to_int(string str, char target) {
    vector<int> res;
    istringstream ss(str);
    string strBuffer;
    while (getline(ss, strBuffer, target))
    {
       res.push_back(stoi(strBuffer));
    }
    return res;
}

int cal_cidr( vector<vector<int> > &int_ip_list, int n) {
    int cidr = 0;
    for (int i = 0; i < 4; ++i) {
        for (int bit = 7; bit >= 0; --bit) {
            for (int idx = 1; idx < n; ++idx) {
                int beforeBit = int_ip_list[idx-1][i] & ( 1 << bit);
                int nowBit = int_ip_list[idx][i] & ( 1 << bit);

                if (beforeBit != nowBit ) {
                    return cidr;
                }
            }
            ++cidr;
        }
    }
    return cidr;
} 

vector<int> cidr_to_subnet_bit(int cidr) {
    vector<int> subnet_bit = {0, 0, 0, 0};

    for (int i = 0; i < 4; ++i) {
        if (cidr == 0) return subnet_bit;
        for (int bit = 7; bit >= 0; --bit) {
            subnet_bit[i] |= (1 << bit);
            --cidr;
            if (cidr == 0) return subnet_bit;
        }
        if (cidr == 0) return subnet_bit;
    }
    return subnet_bit;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> ip_list(n);
    for (string &ip : ip_list) cin >> ip;

    if (n == 1) {
        cout << ip_list[0] << '\n';
        cout << "255.255.255.255";
        return 0;
    }

    vector< vector<int> > int_ip_list(n);
    for (int i = 0; i < n; ++i) {
        int_ip_list[i] = split_to_int(ip_list[i], '.');
    }
    
    int cidr = cal_cidr(int_ip_list, n);
    vector<int> subnet_mask = cidr_to_subnet_bit(cidr);

    // network.ip
    for (int i = 0; i < 4; ++i) {
        cout << (int_ip_list[0][i] & subnet_mask[i]);
        if (i < 3) cout << '.';
    }
    cout << '\n';
    // subnet_mask
    for (int i = 0; i < 4; ++i) {
        cout << subnet_mask[i];
        if (i < 3) cout << '.';
    }

    return 0;
}