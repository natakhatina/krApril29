#include <iostream>
#include <math.h>

void massive1 (int *p, int n);
void massive2 (int *a,int *p, int n);
void PRINT (int *p, int n);
void task456 (int *a, int k);
int schet(int n);


int main() {
    int n=60;
    int *p=(int *) calloc(n,4);
        massive1(p,n);
        PRINT (p,n);
        printf("\n");
    int k=n/2;
    int *a=(int *) calloc(k,4);
        massive2(a,p,k);
        PRINT (a,k);
        printf("\n");
        free(p);
    task456(a,k);
    printf("\n");
    free(a);
    return 0;
}





void massive1 (int *p,int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++, p++) {
        *p = rand() % 10000;
    }
}
void PRINT (int *p,int n) {
    for (int i = 0; i < n; i++, p++) {
        printf("%c%c%d%c%c%-5d\n", 'M','[',i,']','=',*p);
    }
}

void massive2 (int *a,int *p,int n) {
    for (int i = 0; i < n; i++, p=p+2,a++) {
            *a=*p;
    }
}

int schet(int n) {
    int kol=0;
    if (n/10==0)
        return 1;
    else {
        while (n>0) {
            n=n/10;
            kol+=1;
        }
        return kol;
    }

};

void task456 (int *a, int k) {
int **M=(int **)malloc(8*k);
int Summ;
    for (int i = 0; i < k; i++, a++){
        Summ=schet (*a);
        printf("%c%c%d%2c",'S','=',Summ,' ');

        M[i]=(int *) malloc (8*Summ);
        for (int j = 0; j < Summ; j++) {
            M[i][j] = (*a/pow(10,Summ-j))%pow(10,j);
            printf("%-3d", M[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < k; i++){
        if (M[i][1]=0){
            M[i][1]=9;
        }
      else M[i][1]=M[i][1]-1;
        printf("%3d",M[i][1]);
    }

    for (int i = 0; i < k; i++)
        free(M[i]);
    free(M);
}















