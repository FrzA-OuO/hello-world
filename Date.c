/* 从1752年9月3日到1752年9月13日的11天并不存在。 */
/* 没有0年 */
#include <stdio.h>
struct Date {
    int year;
    int month;
    int day;
};

int cnt[ 15 ] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int cntl[ 15 ] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isLeap( int YY );
void next_day( struct Date* day );
void previous_day( struct Date* day );
int equal( struct Date one, struct Date day );
void show( struct Date day );


int main() {
    struct Date today = {2018, 3, 20};
    struct Date day = {2018, 3, 20};
    show( day );
    int i;
    for( i = 0; i < 30; i++ )
        next_day( &day );
    show( day );
    for( i = 0; i < 30; i++ )
        previous_day( &day );
    show( day );
    if( equal( today, day ) )
        printf( "Very Good!\n" );
    else
        printf( "Very Bad!\n" );
    return 0;
}

void next_day( struct Date* day )
{
    day -> day ++;
    if( isLeap( day -> year )){
        if( day -> day > cntl[ day -> month ] ){
            day -> day = 1;
            day -> month ++;
        }
    }
    else{
        if( day -> day > cnt[ day -> month ] ){
            day -> day = 1;
            day -> month ++;
        }
    }
    if( day -> month > 12 ){
        day -> month = 1;
        day -> year ++;
    }
    if( day -> year == 0 ){
        day -> year++;
    }
    
    if( day -> year == 1752 && day -> month == 9 && day -> day == 3 ){
        day -> day = 14;
    }
    
    return;
}

void previous_day( struct Date* day )
{
    day -> day--;
    if( day -> day <= 0 ){
        day -> month--;
        if( day -> month <= 0 ){
            day -> month = 12;
            day -> year --;
        }
        if( isLeap( day -> year )){
            day -> day = cntl[ day -> month ];
        }
        else{
            day -> day = cnt[ day -> month ];
        }
    }
    if( day -> year == 0 ){
        day -> year++;
    }
    
    if( day -> year == 1752 && day -> month == 9 && day -> day == 13 ){
        day -> day = 2;
    }
    
    return;
}

int equal( struct Date one, struct Date day )
{
    if( one.day == day.day && one.month == day.month 
            && one.year == day.year ){
        return 1;
    }
    else{
        return 0;
    }
}

int isLeap( int YY )
{
    if( (YY % 4 == 0 && YY % 100 != 0) || (YY % 400 == 0 ) )
        return 1;
    else return 0;
}

void show( struct Date day )
{
    printf("%d-%d-%d\n", day.year, day.month, day.day);
}
