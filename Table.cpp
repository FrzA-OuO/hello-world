// ver 0.9

// include part
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// define part
#define MAXROW 2048
#define MAXCOLUMN 256

/// public function
void int2str(const int temp_int, string &temp_string)  
{  
    stringstream stream;  
    stream << temp_int;
    stream >> temp_string;
}  

void str2int(int &temp_int, const string &temp_string)  
{  
    stringstream stream(temp_string);  
    stream >> temp_int;  
}  

bool isInArea( int n, int left, int right )
{
    if( n >= left && n <= right ){
        return true;
    }
    else return false;
}

class Table{
    public:
        Table();
        Table( int a, int b );
        void show() const;
        void addRow();
        void addRow( const int currentRow );
        void addRows( const int n );
        void addColumn();
        void addColumn( const int currentColumn );
        void addColumns( const int n );
        void set( const int row, const int column, string str);
        void set( const int row, const int column, const int number);
        void delRow( const int currentRow );
        void delColumn( const int currentColumn);
    private:
        // vector< vector<string> > array;
        vector< vector<string> > vrow;
        int _lastrow, _lastcolumn; // the next number of idx
        
};

// constructor
Table::Table()
{
    // for( int i = 0; i < MAXROW; i++ ){
    //     array[ i ].resize( MAXCOLUMN );
    // }
    // 每一层用vector实现
    
    
    _lastcolumn = 0;
    _lastrow = 0;
}

Table::Table( int a, int b)
{
    _lastcolumn = 0;
    _lastrow = 0;
    
    addRows( a );
    addColumns( b );
}

void Table::show() const
{
    cout << "Row: " << _lastrow << "; " << "Column: " << _lastcolumn << endl;
    for( int i = 0; i < _lastrow; i++ ){
        for( int j = 0; j < _lastcolumn; j++ ){
            if( j == 0 ){
                cout << vrow[ i ][ j ];
            }
            else{
                cout << "\t| " << vrow[ i ][ j ];
            }
        }
        cout << endl;
    }
}

void Table::addRow()
{
    _lastrow++;
    
    vector <string> tv(_lastcolumn);
    vrow.push_back( tv );
}

void Table::addColumn()
{
    
    for( int i = 0; i < _lastrow; i++ ){
        vrow[ i ].push_back("");
    }
    
    _lastcolumn++;
}


void Table::addRow( const int currentRow )
{
    if( isInArea( currentRow-1, 0, _lastrow - 1) ){
        vector <string> tv( _lastcolumn );
        vrow.insert( vrow.begin() + (currentRow-1), tv );
    }
    else{
        cout << "Error: Unexpected Input: \"" << currentRow << '\"' << endl;
    }
}

void Table::addColumn( const int currentColumn )
{
    // vector<string>::iterator it;
    if( isInArea( currentColumn - 1, 0, _lastcolumn - 1) ){
        for( int i = 0; i < _lastrow; i++ ){
            vrow[ i ].insert( vrow[ i ].begin() + (currentColumn-1), "");
        }
    
        _lastcolumn++;
    }
    else{
        cout << "Error: Unexpected Input: \"" << currentColumn << '\"' << endl;
    }
}

void Table::addRows( const int n )
{
    _lastrow += n;
    
    for( int i = 1; i <= n; i++ ){
        vector <string> tv(_lastcolumn);
        vrow.push_back( tv );
    }
}

void Table::addColumns( const int n )
{
    for( int i = 0; i < _lastrow; i++ ){
        for( int j = 1; j <= n; j++ ){
            vrow[ i ].push_back("");
        }
    }
    _lastcolumn += n;

}

void Table::set( const int row, const int column, string str)
{
    vrow[ row - 1 ][ column - 1 ] = str;
}

void Table::set( const int row, const int column, const int number)
{
    string str;
    int2str( number, str );
    vrow[ row - 1 ][ column - 1 ] = str;
}

void Table::delRow( const int currentRow )
{
    if( isInArea( currentRow - 1, 0, _lastrow - 1 ) ){
        vrow.erase( vrow.begin() + (currentRow - 1) );
        _lastrow--;
    }
    else{
        cout << "Error: Unexpected Input: \"" << currentRow << '\"' << endl;
    }
}

void Table::delColumn( const int currentColumn)
{
    
    if( isInArea( currentColumn - 1, 0, _lastcolumn - 1 )){
        for( int i = 0; i < _lastrow; i++ ){
            vrow[ i ].erase( vrow[ i ].begin() + (currentColumn-1));
        }

        _lastcolumn--;
    }
    else{
        cout << "Error: Unexpected Input: \"" << currentColumn << '\"' << endl;
    }
}


int main() 
{
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  tb.addColumn();
  tb.show();
  
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  
  return 0;
}