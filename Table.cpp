// include part
#include <iostream>
#include <vector>

using namespace std;

// define part
#define MAXROW 2048
#define MAXCOLUMN 256


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
        void set( const int row, const int column, string str);
        void set( const int row, const int column, const int number);
        void delRow( const int currentRow );
        void delColumn( const int currentColumn);
    private:
        vector< vector<string> > array;
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

Table::Table( int a, int b){
    _lastcolumn = b;
    _lastrow = a;
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
                cout << " | " << vrow[ i ][ j ];
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
    /*
    vector<string>::iterator it;

    for(it=it.begin();it!=it.end();it++){
        it.push_back("");
    }
    */
    
    for( int i = 0; i < _lastrow; i++ ){
        vrow[ i ].push_back("");
    }
    
    _lastcolumn++;
}


void Table::addRow( const int currentRow )
{
    vector <string> tv( _lastcolumn );
    vrow.insert( vrow.begin() + (currentRow-1), tv );
}

void Table::addColumn( const int currentColumn ){
    // vector<string>::iterator it;

    for( int i = 0; i < _lastrow; i++ ){
        vrow[ i ].insert( vrow[ i ].begin() + (currentColumn-1), "");
    }
    
    _lastcolumn++;
}

int main() {
  cout << "go" << endl;
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  tb.addColumn();
  tb.show();
  /* 
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  */
  return 0;
}
