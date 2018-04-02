#include <iostream>

int cnt[ 15 ] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int cntl[ 15 ] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
    public:
        Date(int y, int m, int d);
        ~Date();

        void nextDay();
        void previousDay();
        bool equal(Date other);
        void show();
        bool isLeap();
        bool isLeap( int YY );
    private:
        int year;
        int month;
        int day;
};

Date::Date( int y, int m, int d )
{
    year = y;
    month = m;
    day = d;
}

Date::~Date(){}

void Date::nextDay()
{
    day++;
    if( isLeap( year )){
        if( day > cntl[ month ] ){
            day = 1;
            month ++;
        }
    }
    else{
        if( day > cnt[ month ] ){
            day = 1;
            month ++;
        }
    }
    if( month > 12 ){
        month = 1;
        year ++;
    }
    if( year == 0 ){
        year++;
    }
    
    if( year == 1752 && month == 9 && day == 3 ){
        day = 14;
    }
    
    return;
}

void Date::previousDay()
{
    day--;
    if( day <= 0 ){
        month--;
        if( month <= 0 ){
            month = 12;
            year --;
        }
        if( isLeap( year )){
            day = cntl[ month ];
        }
        else{
            day = cnt[ month ];
        }
    }
    if( year == 0 ){
        year++;
    }
    
    if( year == 1752 && month == 9 && day == 13 ){
        day = 2;
    }
    
    return;
}

bool Date::equal( Date other )
{
    if( year == other.year && month == other.month
            && day == other.day ){
        return true;
    }
    else{
        return false;
    }
}

void Date::show()
{
    std::cout << year << "-" << month << "-" << day << std::endl;
    return;
}

bool Date::isLeap()
{
    if( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 ) )
        return true;
    else return false;
}

bool Date::isLeap( int YY )
{
    if( (YY % 4 == 0 && YY % 100 != 0) || (YY % 400 == 0 ) )
        return 1;
    else return 0;
}

int main() {
    Date today(2018,3,20);
    Date day(2018,3,20);
    day.show();
    for(int i=0; i<30; i++)
        day.nextDay();
    day.show();
    for(int i=0; i<30; i++)
        day.previousDay();
    day.show();
    if(day.equal(today))
        printf("Very Good!\n");
    else
        printf("Very Bad!\n");
    return 0;
}
