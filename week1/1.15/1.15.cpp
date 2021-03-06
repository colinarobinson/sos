// Generic findMax, with a function object, C++ style.
// Precondition: a.size( ) > 0.
template <typename Object, typename Comparator>
const Object & findMax( const vector<Object> & arr, Comparator isLessThan )
{
    int maxIndex = 0;

    for( int i = 1; i < arr.size( ); i++ )
        if( isLessThan( arr[ maxIndex ], arr[ i ] ) )
            maxIndex = i;

    return arr[ maxIndex ];
}

// Generic findMax, using default ordering.
#include <functional>
template <typename Object>
const Object & findMax( const vector<Object> & arr )
{
    return findMax( arr, less<Object>( ) );
}

class CaseInsensitiveCompare
{
  public:
    bool operator( )( const string & lhs, const string & rhs ) const
      { return stricmp( lhs.c_str( ), rhs.c_str( ) ) < 0; }
};

#include <string>

struct Employee{
string name;
float salary;
};

int main( )
{
    vector<Employee> arr( 3 );
    arr[ 0 ].name = "Zoe"; arr[ 1 ].name = "Alan"; arr[ 2 ].name = "l'Engle";
    cout << findMax( arr, CaseInsensitiveCompare( ) ) << endl;
    cout << findMax( arr ) << endl;

    return 0;
}
