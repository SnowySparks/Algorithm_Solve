#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dt[3][2];

int tl, th;
void did(int loc, int d) {
    if (d == 0) {
        tl+=dt[loc][0];
        th+=dt[loc][1];
    }
    else {
        tl+=dt[loc][0];
    }
}
int main(void) {

    
}