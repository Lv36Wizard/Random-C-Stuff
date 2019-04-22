// Testing for the LinkedList class

#include "LinkedList.h"

#include <iostream> // For cout
using namespace std;

int main( int argc, char **argv )
{
  cout << "A test program for the LinkedList class.\n"
       << "To enable DEBUG settings and output, compile with:\n"
       << "g++ -D DEBUG LinkedListTest.cc -o LinkedListTest.run\n\n";
  // Testing with a list of integers:
  { // Scope used to deallocate list memory once uneeded
    cout << "Testing list filled with integers:\n";
    LinkedList<int> list;
    for ( int i = 0; i < 20; i++ ){
      list.push( i );
    }

    int cols = 0;
    for ( int i = 0; i < 20; ++i ){
      // Note the dereference; the LinkedList class returns a pointer
      // from the get(...) method, allowing it to return a nullptr
      // if required, as well as handle both pointer and actual data.
      cout << *list.get( i );
      if ( cols == 9 ) {
        cols = 0;
        cout << ",\n";
      }
      else{
        cout << ", ";
        ++cols;
      }
    }
  }

  // Testing with a list of pointers to integers:
  { // Scope used to deallocate list memory once uneeded
    cout << "\nTesting list filled with pointers to integers:\n";
    int ints[20];
    LinkedList<int*> list;
    for ( int i = 0; i < 20; i++ ){
      ints[i] = i;
      list.push( &ints[i] );
    }
    int cols = 0;
    for ( int i = 0; i < 20; ++i ){
      // Note the dereference; the LinkedList class returns a pointer
      // from the get(...) method, allowing it to return a nullptr
      // if required, as well as handle both pointer and actual data.
      cout << **list.get( i );
      if ( cols == 9 ) {
        cols = 0;
        cout << ",\n";
      }
      else{
        cout << ", ";
        ++cols;
      }
    }
  }
}
