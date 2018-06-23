#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class Clock {
public:
    Clock();
    void tick();
    void show() const;
    void adjust( int hh, int mm, int ss );

private:
    int HH, MM, SS;
};

Clock::Clock()
{
    HH = 10;
    MM = 10;
    SS = 20;
}

void Clock::tick()
{
    SS++;
    if( SS == 60 ){
        MM++;
        SS = 0;
    }
    if( MM == 60 ){
        HH ++;
        SS = 0;
    }
    if( SS == 24 ){
        SS = 0;
    }
}

void Clock::show() const{
    printf("Current Time: %02d:%02d:%02d\n", HH, MM, SS);
}

void Clock::adjust( int hh, int mm, int ss ){
    if( hh >= 0 && hh < 24 && mm >= 0 && mm < 60 && ss >= 0 && ss < 60 ){
        HH = hh;
        MM = mm;
        SS = ss;
    }
    else{
        printf("Error: Illegal argument\n");
    }
}

int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
