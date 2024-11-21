#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define f(a, b, c) for (int a = b; a < c; a++)
using namespace std;

int strto(const string &s)
{
    if (s.size() <= 4) return 0;
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

unordered_map<string, long double> dist = {
	{ "Seoul", 0.0 },
	{ "Yeongdeungpo", 9.1 },
	{ "Anyang", 23.9 },
	{ "Suwon", 41.5 },
	{ "Osan", 56.5 },
	{ "Seojeongri", 66.5 },
	{ "Pyeongtaek", 75.0 },
	{ "Seonghwan", 84.4 },
	{ "Cheonan", 96.6 },
	{ "Sojeongni", 107.4 },
	{ "Jeonui", 114.9 },
	{ "Jochiwon", 129.3 },
	{ "Bugang", 139.8 },
	{ "Sintanjin", 151.9 },
	{ "Daejeon", 166.3 },
	{ "Okcheon", 182.5 },
	{ "Iwon", 190.8 },
	{ "Jitan", 196.4 },
	{ "Simcheon", 200.8 },
	{ "Gakgye", 204.6 },
	{ "Yeongdong", 211.6 },
	{ "Hwanggan", 226.2 },
	{ "Chupungnyeong", 234.7 },
	{ "Gimcheon", 253.8 },
	{ "Gumi", 276.7 },
	{ "Sagok", 281.3 },
	{ "Yangmok", 289.5 },
	{ "Waegwan", 296.0 },
	{ "Sindong", 305.9 },
	{ "Daegu", 323.1 },
	{ "Dongdaegu", 326.3 },
	{ "Gyeongsan", 338.6 },
	{ "Namseonghyeon", 353.1 },
	{ "Cheongdo", 361.8 },
	{ "Sangdong", 372.2 },
	{ "Miryang", 381.6 },
	{ "Samnangjin", 394.1 },
	{ "Wondong", 403.2 },
	{ "Mulgeum", 412.4 },
	{ "Hwamyeong", 421.8 },
	{ "Gupo", 425.2 },
	{ "Sasang", 430.3 },
	{ "Busan", 441.7 }
};

unordered_map<string,pair<int, int> > tm = {};


    

int main(void)
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); cout.precision(12);
    string a,b,c;
    int n, q; cin >> n >> q;
    f(i,0,n) {
        cin >> a >> b >> c;
        tm[a]= {strto(b),strto(c)};
    }
	f(i,0,q) {
		cin >> a >> b;
		long double d = abs(dist[a] - dist[b]);
		int time = (tm[a].second < tm[b].first) ? tm[b].first - tm[a].second : tm[b].first + 24*60 - tm[a].second;
		cout << d/time*60 << '\n';
	}
    return 0;
}