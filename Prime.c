/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,
所有数字之积以及所有数字的平方和都是素数.例如113就是一个
超级素数.求[100,9999]之内:
(1)超级素数的个数.
(2)所有超级素数之和.
(3)最大的超级素数.
*/
#include <stdio.h>
#include <math.h>
#define MAXN 10010
short isp[ MAXN ] = {0};
void Getprime( int n ){
    int i, j;
    for( i = 2; i <= n; i++ )
        isp[ i ] = 1;
    
    
    for( i = 2; i <= n; i++ ){
        if( isp[ i ] ) {
            for( j = 2; (long long) i * j <= n; j++ ){
                isp[ i * j ] = 0;
            }
        }
    }
}

int sum_bit(int num) {
    int s = 0;
    
    while( num != 0 ){
        s += num % 10;
        num /= 10;
    }

    return s;
}

int multi_bit(int num) {
    int s = 1;
    
    while( num != 0 ){
        s *= num % 10;
        num /= 10;
    }
    return s;
}

int square_sum_bit(int num) {
    int s = 0;
    while( num != 0 ){
        s += (num % 10)*(num % 10);
        num /= 10;
    }
    return s;
}

int isprime(int num) {
    return isp[ num ];
}

int main() {
    
    int l = 100, r = 9999;
    int maxP = -1, cntP = 0, sumP = 0;
    int i;
    
    Getprime( r );
        
    for( i = l; i <= r; i++ ){

        if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i))){
      
            //to do sth
            // printf("%d is SuperPrime \n", i);
            maxP = i;
            cntP ++;
            sumP += i;
        }
    }
    
    printf("There's %d Superprime(s) in [%d, %d];\n", cntP, l, r);
    printf("The sum is %d;\n", sumP);
    printf("The maximum Superprime is %d.\n", maxP);
    
    return 0;
}
