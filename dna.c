#include <stdio.h>

#include "dna.h"


void load_string(FILE *file, int *p, char *s, int t) {
    if (fscanf(file, "%d", p) != 1) {
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do {
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}


int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
    if(n == 0 || m == 0){
        length[n][m] = 0;
        return length[n][m];
    }else if(length[n][m] != -1){
        return length[n][m];
    }else if(a[n-1] == b[m-1]){
        length[n][m] =  1 +  mlcs_w(a,n-1,b,m-1,length);
        return length[n][m];
    }else {
        int n1 = mlcs_w(a,n-1,b,m,length);
        int m1 = mlcs_w(a,n,b,m-1,length);
        if(n1 > m1){
            length[n][m] = n1;
            return length[n][m];
        } 
        length[n][m] = m1;
        return length[n][m];
    }
}
int mlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE + 1][MAX_SIZE + 1];
    
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            length[i][j] = -1; 
        }
    }
    return mlcs_w(a,n,b,m,length);
}
int dlcs(char a[], int n, char b[], int m) {

    int length[MAX_SIZE + 1][MAX_SIZE + 1];
    int max = 0;
    int left, right;

    for(int i = 0; i <= n; i++){

        for(int j = 0; j <= m; j++){

            if(i == 0 || j == 0){
                length[i][j] = 0;
            }else if(a[i-1] == b[j-1]){
                length[i][j] = length[i-1][j-1] + 1;
            }else{
                left = length[i-1][j];
                right = length[i][j-1];
                length[i][j] = right;
                if(left > right){
                   length[i][j] = left;
                } 
            }  
            if(length[i][j]> max){
            max = length[i][j];
            }
        }
    }
    return max;
}

