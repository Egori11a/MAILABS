#include<stdio.h>
#include<string.h>
#include<limits.h>
#define max 99999

int main(){
    FILE *file = fopen("test.txt", "r");
    char m[max]; //Input string
    char req[max];//answer
    int B;//support answer to record the answer correctly
    int bg_check_pred=0;//an indicator that the 16-ss number has ended
    int bg_check=0;//an indication that the 16-cc number has started
    int lt_check=0;//counter of the number of 16-ss numbers
    fgets(m, max, file);
    char alf[17]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '*'};
    int len_string = strlen(m);
    printf("%s\n", m);
    for(int i=len_string-1; i>=0; i--){
        for(int j=0; j<=16; j++){
            if(m[i]==alf[j]){
                bg_check_pred=bg_check;
                bg_check++;
                break;
            }
            else if(alf[j]=='*' && bg_check!=0){ //if * then the 16-ss number is cut off and we can calculate +1 number
                bg_check=0;
                lt_check++;
            }
        }
        if(bg_check*lt_check!=0){//check the condition is that the first 16--ss number has already passed and the second one has begun
            //printf("%c", m[i]);
            req[B]=m[i]; //we write it down in response
            B++;
        }
        if(bg_check_pred>bg_check && lt_check>1){ //if 16-ss the number broke off and it is the second, then we go out
            break;
        }
        printf("pred:%d bg:%d lt:%d %c\n", bg_check_pred, bg_check, lt_check, m[i]);
    }
    int check_zero=0;
    for(int i=0; i<=strlen(req)-1; i++){//fix no matter zero
        if(req[i]=='0'){
            check_zero++;
        }
        else{
            check_zero=0;
        }
    }
    for(int i=strlen(req)-1-check_zero; i>=0; i--){ //he answer is written in mirror form, so let's turn it over
        printf("%c", req[i]);
    }
    return 0;
}
