#include<stdio.h>
#include<math.h>
#include<assert.h>

int digit_counter(int a){
    int c=0;
    while(a!=0){
        c++;
        a/=10;
    }
    return c;
}

void test_digit_counter(){
    assert(digit_counter(123)==3);
    assert(digit_counter(101)==3);
    assert(digit_counter(010)==2);
    assert(digit_counter(1)==1);
    assert(digit_counter(5555)==4);
}

int main(){
    FILE *file = fopen("test.txt", "r");
    for(int i=0; i<10; i++){
        int a;
        int c;
        fscanf(file, "%d", &a);
        printf("Before: %d ", a);
        c=(a%10*pow(10, digit_counter(a))+a)/10;
        printf("After: %d\n", c);
    }
    return 0;
}
