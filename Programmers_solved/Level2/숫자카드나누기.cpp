#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA, gcdB;
    
    gcdA = arrayA[0];
    gcdB = arrayB[0];
    
    for (int i = 1 ; i < arrayA.size();i++) {
        gcdA = gcd(gcdA,arrayA[i]);
        gcdB = gcd(gcdB,arrayB[i]);
    }
    if (gcdA == gcdB) return 0;
    
    bool A = true, B = true;
    
    for (auto e : arrayB) {
        if (e%gcdA == 0) {
            A = false; break;
        }
    }
    for (auto e : arrayA) {
        if (e % gcdB == 0) {
            B = false; break;
        }
    }
    
    if (A&B) return max(gcdA,gcdB);
    else if (A) return gcdA;
    else if (B) return gcdB;
    else return 0;
}