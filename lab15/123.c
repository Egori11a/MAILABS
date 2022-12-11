#include <stdio.h>

int main() {
	int n, i, j;
	printf("Write n: ");
	scanf("%d", &n);
	int m[n+1][n+1];
	printf("Write elems:\n");
	for (int i = 1; i <= n; i++ ) {
		for (int j = 1; j <= n; j++ ) {
			scanf("%d", &m[i][j]);
		}
	}
	//transpon m
	int trans_m[n+1][n+1];
	for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            trans_m[i][j]=m[j][i];
        }
	}
	//kostyl
	int new_m[n+1][n+1];
	for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            new_m[i][j]=0;
        }
	}
	//ymnojjenie
	for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            for(int k=1;k<n+1;k++){
                new_m[i][j]+=m[i][k]*trans_m[k][j];
            }
        }
	}
	//print
	for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            printf("%d\t", new_m[i][j]);
        }
	}
	return 0;
}
