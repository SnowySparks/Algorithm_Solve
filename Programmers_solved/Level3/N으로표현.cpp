#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


//N , NN , NNNN 이런 식으로 된 숫자 출력
int to_setnum(const int &num, const int &length) {
    int result=num;

    for (int i=1;i<=length;i++) {
        result=num+result*10;
    }
    return result;
}

int solution(int N, int number) {
    unordered_set<int> save[8];//hash꼴인 set, O(1)
    for (int i=0;i<8;i++) {//i=0 -> 1자리 , i=1-> 2자리
        save[i].insert(to_setnum(N,i));//NN... 대입
        for (int k=0;k<i;k++) {
            for (int j=0;j<i;j++) {
                if (k+j+1!=i) {
                    continue;
                }//k+j+2 = i+1 꼴이 되는 k,j를 찾아 save[k],save[j] 에대한 모든 사칙연산 조합
                //단 0초과값만 받아야하며, 나누기는 /0 주의
                else {
                    for (auto e : save[k]) {
                        for (auto p : save[j]) {
                            save[i].insert(e+p);
                            if (e-p>0) {
                                save[i].insert(e-p);
                            }
                            if (e*p!=0) {
                                save[i].insert(e*p);
                                save[i].insert(e/p);
                            }
                        }
                    }
                }
            }
        }
        //각 자리수 계산 끝날때마다 원하는 값이 있는지 판단, 발견시 그 즉시 출력하여 종료
    if (save[i].find(number)!=save[i].end()) {
        return i+1;
    }
    }
    //없으면 -1
    return -1;
}