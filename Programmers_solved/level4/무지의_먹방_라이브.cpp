#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct food_datas {
    long long food_time;
    int idx;
} fdt;

struct comp {
    bool operator()(const fdt &a, const fdt &b) {return a.food_time > b.food_time;}
};
bool cmp (const fdt &a, const fdt &b) {return a.idx < b.idx;}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long total_time = 0;
    long long before = 0; //이전 섭취 단위 시간 크기
    long long now;
    long long sum_times = 0; //누적된 시간;
    priority_queue<fdt,vector<fdt>,comp> pq;
    for (int i = 0 ; i < food_times.size(); i++) {
        pq.push({food_times[i],i+1});
        total_time += (long long)food_times[i]; 
    }
    if (total_time <= k) return -1; //더이상 음식이 존재x

    while (sum_times + ((pq.top().food_time - before) * pq.size()) <= k) {
        now = pq.top().food_time;
        sum_times += (now - before) * pq.size();
        while (now >= pq.top().food_time) {pq.pop();}
        before = now;
    }

    vector<fdt> lasts;
    while (!pq.empty()) {
        lasts.push_back(pq.top());
        pq.pop();
    }
    sort(lasts.begin(), lasts.end(),cmp);
    return lasts[(k-sum_times) % lasts.size()].idx;
}