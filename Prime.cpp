#include <iostream>
#define MAXN 10010

bool isp[ MAXN ] = {0};

void Getprime( int n ){
    int i, j;
    for( i = 2; i <= n; i++ )
        isp[ i ] = true;
    
    
    for( i = 2; i <= n; i++ ){
        if( isp[ i ] ) {
            for( j = 2; (long long) i * j <= n; j++ ){
                isp[ i * j ] = false;
            }
        }
    }
}

class Prime {
    public:
        Prime(int num);
        ~Prime();
        
        bool isPrime();
        
        Prime sumBit();
        Prime multiBit();
        Prime squareSumBit();
    private:
        const int mNum;
};

Prime::Prime( int num ):mNum( num ){}

bool Prime::isPrime()
{
    return isp[ mNum ];
}

Prime Prime::sumBit()
{
    int s = 0;
    int k = mNum;
    while( k != 0 ){
        s += k % 10;
        k /= 10;
    }

    return s;
}

Prime Prime::multiBit()
{
    int s = 1;
    int k = mNum;

    while( k != 0 ){
        s *= k % 10;
        k /= 10;
    }

    return s;
}

Prime Prime::squareSumBit()
{
    int s = 0;
    int k = mNum;
    while( k != 0 ){
        s += (k % 10)*(k % 10);
        k /= 10;
    }

    return s;
}

Prime::~Prime(){}

int main() {
    int l = 100, r = 9999;
    int maxP = -1, cntP = 0, sumP = 0;
    
    Getprime( r );
    
    for( int i = l; i <= r; i++ ){
        // Prime pm(113);
        Prime pm( i );
        Prime sb = pm.sumBit();
        Prime mb = pm.multiBit();
        Prime ssb = pm.squareSumBit();
        if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
            //to do sth
            // std::cout << i << " is a SuperPrime\n";
            maxP = i;
            cntP ++;
            sumP += i;
        }
        /* 
        else{
            std::cout << i << " isn't a SuperPrime\n";
        } */
    }
    
    std::cout << "There's " << cntP << " Superprime(s) in [" << l << ", " << r << "];\n";
    std::cout << "The sum is " << sumP << ";\n";
    std::cout << "The maximum Superprime is " << maxP << std::endl;
    return 0;
}
