/* 

https://blog.csdn.net/u013421892/article/details/51201377

继承时的构造原则：

1、如果子类没有定义构造函数，那子类就是调用父类的无参数的构造函数。

2、如果子类定义了构造函数，那么不管父类有没有定义构造函数，在创建子类对象时，首先会调用父类的无参数的构造函数，然后在调用子类自己的构造函数。

3、在创建一个子类对象时，如果子类没有显示调用父类的构造函数，那么就会首先调用父类的默认的无参的构造函数（其实和上面的2是一样的）。

4、在创建子类对象时，如果此时父类有自己书写了无参的构造函数，此时如果子类没有显示的调用父类的构造函数，那就就会首先调用父类自己书写的的无参的构造函数。

5、在创建子类对象时，如果父类只有有参的构造函数，子类没有显示的调用的父类的构造函数，则会出错。因为如果父类只有有参的构造函数，那么子类就必须显示调用父类有参的构造函数，

6、如果子类显示调用父类的有参构造函数，那么必须使用初始化列表形式进行初始化。

*/

#include <iostream>
#define MAXN 10010
using namespace std;
 
// get all primes
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

// def of class Prime
class Prime {
public:
    Prime( int num );
    ~Prime();

    bool isPrime();
private:
    const int mNum;
};

Prime::Prime( int num ):mNum( num ){}

bool Prime::isPrime()
{
    return isp[ mNum ];
}

Prime::~Prime(){}

// def of class SuperPrime extends from Prime
class SuperPrime : public Prime {
public:
    SuperPrime( int num );
    ~SuperPrime();

    bool isPrime();

    Prime sumBit();
    Prime multiBit();
    Prime squareSumBit();
private:
    const int num;
};

SuperPrime::SuperPrime( int num ):Prime( num ), num( num ){}

bool SuperPrime::isPrime()
{
    return ( isp[ num ] && sumBit().isPrime() && multiBit().isPrime() && squareSumBit().isPrime() );
}

Prime SuperPrime::sumBit()
{
    int s = 0;
    int k = num;
    while( k != 0 ){
        s += k % 10;
        k /= 10;
    }

    return s;
}

Prime SuperPrime::multiBit()
{
    int s = 1;
    int k = num;

    while( k != 0 ){
        s *= k % 10;
        k /= 10;
    }

    return s;
}

Prime SuperPrime::squareSumBit()
{
    int s = 0;
    int k = num;
    while( k != 0 ){
        s += (k % 10)*(k % 10);
        k /= 10;
    }

    return s;
}

SuperPrime::~SuperPrime(){}

int main()
{
    int l = 100, r = 9999;
    int maxP = -1, cntP = 0, sumP = 0;
    
    Getprime( r );
    
    for( int i = l; i <= r; i++ ){
        SuperPrime sp( i );
        if(sp.isPrime()) {
            // cout << "1" <<endl; 
            // do something
            maxP = i;
            cntP ++;
            sumP += i;
        }
    }
    
    std::cout << "There's " << cntP << " Superprime(s) in [" << l << ", " << r << "];\n";
    std::cout << "The sum is " << sumP << ";\n";
    std::cout << "The maximum Superprime is " << maxP << std::endl;
    
    return 0;
}
