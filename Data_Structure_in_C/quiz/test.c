#include <stdio.h>
#include <stdbool.h>

//수정시 ROW , COL , int A이후의 배열 만 수정하시면 됩니다.

#define ROW 4
#define COL 5


int main(void) {
    int A[ROW][COL]={{1,1,0,0,0},{1,0,1,0,1},{0,0,0,1,1},{0,1,1,1,0}};

    int result[ROW];
    bool euler=true;
    int temp=0;

    for (int i=0;i<ROW;i++) {
        temp=0;
        for (int k=0;k<COL;k++) {
            temp+=A[i][k];
        }
        result[i]=temp;
    }

    for (int i=0;i<ROW;i++) {
        printf("%d Vertex : %d Degrees\n",(i+1),result[i]);
        if (result[i]%2==1) {
            euler=false;
        }
    }
    puts("");
    if (euler==true) {
        printf("이 그래프는 오일러 사이클을 포함합니다.\n");
    }
    else {
        printf("이 그래프는 오일러 사이클을 포함하지 않습니다.\n");
    }

    return 0;
}