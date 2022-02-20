#include <stdio.h>

int foobar(int* n){
     *n = *n +1;
     return *n;
}

int mystery(int p, int q){
     
    int r;
    if ((r = p % q) == 0)
        return q; 
    else return mystery(q, r);
}

int main(){
    //int k = 6;
    //printf("foobar(k) = %d,",foobar(&k) );
    //printf(" k = %d\n", k);
    //printf("mystery(2,6) = %d\n", mystery(2,6));
    int a[10] = {1,2,3,4,5,6,7,8,9,10}, i = 6 ;
    int *p = &a[0];
    printf("%d\n\t\t%d", *(p + i), *p);
}