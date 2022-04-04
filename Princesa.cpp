#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// usando o vector
bool existe( vector<int>& fila, int n)
{
    for( int i = 0; i < fila.size(); i++ ){
        if( fila[i] == n ) 
        return true;
    }
    return false;
}

int main()
{ 
  

}