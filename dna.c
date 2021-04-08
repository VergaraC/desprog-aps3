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
        return 0;
    }else if(a[n-1] == b[m-1]){
        return 1 +  mlcs_w(a,n-1,b,m-1,length);
    }else {
        int n1 = mlcs_w(a,n-1,b,m,length);
        int m1 = mlcs_w(a,n,b,m-1,length);
        if(n1 > m1){
            return n1;
        } 
        return m1;
    }
}
int mlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE + 1][MAX_SIZE + 1];
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            length[i][j] = a[j]; 
        }
    }
    for (int i2 = 0; i2 < n; i2++){
        for (int j2 = 0; j2 < m; j2++){
            length[i2][j2] = b[j2]; 
        }
    }
    return mlcs_w(a,n,b,m,length);
}


int dlcs(char a[], int n, char b[], int m) {

    int length[n + 1][m + 1];

    for(int i = 0; i <= n; i++){

        for(int j = 0; j <= m; j++){

            if(i == 0 || j == 0){
                length[i][j] = 0;
            }else if(a[i-1] == b[j-1]){
                length[i][j] = length[i-1][j-1]+1;
            }else{
                if(length[i-1][j] >  length[i][j-1]){
                   length[i][j] = length[i-1][j];
                }else{
                    length[i][j] = length[i][j-1];
                }
            }   
        }
    }
    return length[n][m];
}

