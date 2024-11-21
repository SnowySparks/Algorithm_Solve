#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    int length = (int) log10(storey)+1;
    int check;
    int ten = 1;
    bool status = false;
    for (int i = 1; i <= length; i++) {
        check = (storey % (10*ten))/ten;
        if (check < 5) status = false;
        else if (check > 5) status = true;
        else if ((storey / (10*ten) % 10 ) >= 5) status = true;
        else status = false;

        if (status == false) {
            answer += check;
            storey -= check * ten;
        }
        else {
            answer += (10-check);
            storey += ten*(10-check);
        }
        ten*=10;
    }
    return answer + storey/(ten);
}