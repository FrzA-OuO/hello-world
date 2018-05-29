#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Parallelogram {
    public:
        Parallelogram();
        Parallelogram( const double length, const double height );
        void show() const;
        double area() const;
        double height() const;
        double height( double _height );
        double length() const;
        double length( double _length );
    private:
        double _length, _height;
};

Parallelogram::Parallelogram()
{
    _length = 0;
    _height = 0;
}

Parallelogram::Parallelogram( const double length, const double height )
{
    _length = length;
    _height = height;
}

double Parallelogram::area() const
{
    return _length * _height;
}
double Parallelogram::height() const
{
    return _height;
}
double Parallelogram::height( double height )
{
    _height = height;
}
double Parallelogram::length() const
{
    return _length;
}
double Parallelogram::length( double length )
{
    _length = length;
}
    
void Parallelogram::show() const
{
    cout << "Parallelogram infomation:\n";
    cout << "length: " << _length << '\n';
    cout << "height: " << _height << '\n';
    cout << "area: " << area() << endl;
}

int main() {
    Parallelogram pg;
    pg.show();
    cout << pg.area() << endl;
  
    cout << pg.height() << endl;
    pg.height( 3 );
    cout << pg.height() << endl;
    
    cout << pg.length() << endl;
    pg.length( 4 );
    cout << pg.length() << endl;
    
    pg.show();
    
    Parallelogram pg2( 6, 8 );
    pg2.show();
    pg2.height( 4 );
    pg2.show();
    
    return 0;
}
