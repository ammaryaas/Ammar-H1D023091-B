#include <stdio.h>

int Fibonacci(int a){
    int awal = 0;
    int dua = 1;
    if(a <= 0){
        return 1;
    }else if (a = 1){
        return 1;
    }else{
        return Fibonacci(a-1) + Fibonacci(a-2);
    }
}

int main(){
    int x;
    printf("masukan data: ");
    scanf("%d", &x);
    printf("%d", Fibonacci(x));
}