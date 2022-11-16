#include<stdio.h>
#include<stdlib.h>
#define min(i, j) (((i) < (j)) ? (i) : (j))
#define max(i, j) (((i) > (j)) ? (i) : (j))

int main(){
    FILE *file;
    file = fopen("test1.txt", "r");
    int n;
    fscanf(file, "%d", &n);
    int ost[3] = {1000000, 1000000, 1000000};
    long s;
    for(int i=0; i<n; i++){
        int a, b, diff;
        fscanf(file, "%d%d", &a, &b);
        s+=min(a, b);
        diff=abs(a-b);
        ost[diff%3]=min(ost[diff%3], diff);
    }
    long res=2147483646;
    if(s%3!=0)
        printf("%d", s);
    else{
        for(int i=0; i<3; i++){
            if(s%3!=i){
                res=min(res, s+ost[i]);
            }
        }
        printf("%d", res);
    }
    fclose(file);
    return 0;
}
