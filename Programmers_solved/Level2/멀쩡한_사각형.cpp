//https://programmers.co.kr/learn/courses/30/lessons/62048
#include <iostream>
using namespace std;

int gcd(int a,int b) {
    int r=a%b;
    if (r==0) {
        return b;
    }
    else {
        return gcd(b,r);
    }
}


long long solution(int w,int h) {
    int gcdm=gcd(w,h);
    int a=w/gcdm;
    int b=h/gcdm;
    long long result=(long long)w*h-(w+h)+gcdm;
    
    return result;
}