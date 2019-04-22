/*******************************************************************************
 * Class: LinkedList
 * Author: Quin J. G. Rider
 * Date of creation: 2018-03-13
 * Last Modified: 2019-04-22
 * 
 * 
 * Note: This is a template class, and as such is entirely contained in this
 *       header file (to avoid manually declaring compatable types).
 *       The forward declarations for functions are provided in the top section
 *       of this header in order to maintain a separated and clean design.
 *       Function instantiations are under "FUNCTION INSTANTIATIONS".
 *
 * Purpose: Implement a doubly linked list with quick sequential manipulations
 *
 * Functions:
 *   + LinkedList() -> Constructor
 *   + ~LinkedList() -> Destructor
 *   + bool add( T, int=-1 ) -> Adds data to the given index - if no index is
 *                              provided, the data is appended to the tail. If
 *                              given index is populated, said node is pushed
 *                              further into the list.
 *                              Returns false is index is out of bounds.
 *                           
 *   + void push( T ) -> Adds data to head of the list
 *   + void append( T ) -> Adds data to the tail of the list
 *
 *   + T pop() -> Calls rem(-1), removing the tail node from the list.
 *                Returns a pointer to the removed data.
 *
 *   + T remAt( int=-1 ) -> Removes node at the given index. Returns a pointer
 *                          to the removed data. If no index is provided,
 *                          the tail is removed (acts as rem(-1)).
 *
 *   + T set( T, int=-1 ) -> Sets data to the specified index. If the
 *                           given index is populated, the already present
 *                           nodes data is set to the new data. Returns
 *                           nullptr unless the index was already 
 *                           populated, in which case, a pointer to the
 *                           old data is returned.
 * 
 *   - N *getDLLNode( int ) -> Get the node at the given index
 *   - T rem
 * 
 * Variables:
 *   - int size -> The number of nodes in this list
 *   - int sentinalIndex  -> Index of the sentinal node
 *   - DLLNode *head; -> Head node of this list
 *   - DLLNode *tail; -> Tail node of this list
 *   - DLLNode *sentinal; -> A node used for quick linear/regional seeks and
 *                           list manipulations (add, rem, get)
 * 
 ******************************************************************************/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  @ CLASSICAL HEADER COMPONENTS:
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#ifndef DLL_ADT
#define DLL_ADT

#include "DLLNode.h"
#define N DLLNode<T> // Typing DLLNode<T> was quite boring and slow


#ifdef DEBUG
// For logging:
#include <stdio.h>
#include <iostream>
using namespace std;
#endif

template <class T> class LinkedList
{
public:
  /*****************************************************************************
   * Name: LinkedList
   * Purpose: Constructor - initializes size variable
   * Arguments: None
   * Return: Memory pointer of new LinkedList object
   ****************************************************************************/
  LinkedList();
  
  /*****************************************************************************
   * Name: ~LinkedList
   * Purpose: Destructor - frees memory allocated for DLLNodes
   * Arguments: None
   * Return: Nothing
   ****************************************************************************/
  ~LinkedList();
  
  /*****************************************************************************
   * Name: add( T , int )
   * Purpose: Add node to the given index
   * Arguments: T (data), int (index)
   * Return: int -> Status:
   *                -1 = fail
   *                 0 = OKAY
   ****************************************************************************/
  int add( T data, int idx );
  
  /*****************************************************************************
   * Name: push( T )
   * Purpose: Push data to the head of the list
   * Arguments: T (data)
   * Return: Nothing
   ****************************************************************************/
  void push( T data );
  
  /*****************************************************************************
   * Name: append( T * )
   * Purpose: Append data to the tail of the list
   * Arguments: T (data)
   * Return: Nothing
   ****************************************************************************/
  void append( T data );
  
  /*****************************************************************************
   * Name: set( T *, int = -1 )
   * Purpose: Set data at the given index
   * Arguments: T * (data), int (index)
   * Return: T -> nullptr unless given index was already populated, in which
   *              case a pointer to the old data is returned.
   ****************************************************************************/
  T set( int idx, T data );
  
  /*****************************************************************************
   * Name: pop()
   * Purpose: Remove data from the head of the list
   * Arguments: None
   * Return: *T -> Pointer to the removed data
   ****************************************************************************/
  T *pop( );
  /*****************************************************************************
   * Name: popTail()
   * Purpose: Remove data from the tail of the list
   * Arguments: None
   * Return: *T -> Pointer to the removed data
   ****************************************************************************/
  T *popTail( );
  /*****************************************************************************
   * Name: remAt( int )
   * Purpose: Remove data from the given index
   * Arguments: int (index)
   * Return: *T -> Pointer to the old data, or nullptr if index is out of bounds
   ****************************************************************************/
  T *remAt( int );
  
  /*****************************************************************************
   * Name: *get( int )
   * Purpose: Return the data from the given index into this list
   * Arguments: int (index)
   * Return: *T -> the data, or nullptr if index is out of bounds / data stored
   *               at the index was a nullptr.
   ****************************************************************************/
  T *get( int );

  /*****************************************************************************
   * Name: size()
   * Purpose: Return the 'size' of this list; the number of nodes.
   * Arguments: None
   * Return: int -> the size of this list measured in node count
   ****************************************************************************/
  int size(){ return this->length; }
  
private:
  int length; // Number of nodes in the list
  N *head; // First node in the list
  N *tail; // Last node in the list

  N *sentinal; // Sentinal node for quick regional searching and
               // list manipulations
  int sIdx; // Sentinal index for distance-to-target calculations

  /*****************************************************************************
   * Name: getDLLNode( int )
   * Purpose: Get the node at the given index
   * Arguments: int (index)
   * Return: *N -> The node at the given index, or nullptr if not valid index
   * 
   * Note: Only for use internally
   ****************************************************************************/
  N *getDLLNode( int );
  /*****************************************************************************
   * Name: rem( DLLNode<T> T *n )
   * Purpose: Remove given node from this list
   * Arguments: DLLNode<T> T *n -> the node to remove
   * Return: T -> the old data, or nullptr if the node given is invalid
   *
   * Note: Only for use internally
   ****************************************************************************/
  T *rem( N * );
};

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 @ FUNCTION INSTANTIATIONS:
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

template <class T> LinkedList<T>::LinkedList()
{
#ifdef DEBUG
  cout << "****************************************\n"
       << "LinkedList created in DEBUG mode:\n"
       << " -> Logging enabled.\n"
       << " -> Function access notificatons enabled\n"
       << "****************************************\n";
#endif
  length = 0;
  head = nullptr;
  tail = nullptr;
  sentinal = nullptr;
}

template <class T> LinkedList<T>::~LinkedList()
{
#ifdef DEBUG
  cout << "In LinkedList<T>::~LinkedList()\n";
#endif
  //****************************************************************************
  // Note that the creator of this list is incharge of cleaning up/freeing
  // the memory of node data in this list - a simple way to do this is to
  // write a loop that calls delete pop() for every node in the list.
  //
  // This simply frees all pointers via pop().
  //****************************************************************************
  while ( head != nullptr ){
    pop();
  }
}

template <class T> T *LinkedList<T>::pop()
{
#ifdef DEBUG
  cout << "In LinkedList<T>::pop()\n";
#endif
  if ( !this->head ){
    return ( nullptr );
  }
  if ( this->length == 0 ) popTail();
  --this->length;
  
  DLLNode<T> *oldHead = this->head;
  this->head = this->head->next;
  T *oldData = &oldHead->data;

  if ( this->length == 1 ){
    this->tail = this->head;
  }

  delete oldHead;
  
  return ( oldData );
}

template <class T> T *LinkedList<T>::popTail()
{
#ifdef DEBUG
  cout << "In LinkedList<T>::popTail()\n";
#endif
  if ( !this->tail ){
    return ( nullptr );
  }
  if ( this->length <= 1 ){
    return ( this->length == 1 ? pop() : nullptr );
  }
  
  --this->length;
  
  DLLNode<T> *oldTail = this->tail;
  this->tail = this->tail->prev;
  this->tail->next = nullptr;
  
  T *oldData = &(oldTail->data);
  
  delete oldTail;

  return ( oldData );
}

template <class T> int LinkedList<T>::add( T data, int idx )
{
#ifdef DEBUG
  cout << "In LinkedList<T>::add(...)\n";
#endif
  if ( idx < 0 || idx > size ){
    return -1;
  }
  if ( !this->head ){
    push( data );
  }
  else if ( idx == size ){
    append( data );
  }
  else{
    ++length;
    
    N *a = new N( data );
    N *b = getDLLNode( idx );
    
    a->next = b;
    a->prev = b->prev;
    b->prev = a;
  }
}

template <class T> void LinkedList<T>::push( T data )
{
#ifdef DEBUG
  cout << "In LinkedList<T>::push(...)\n";
#endif
  ++this->length;

  if ( !this->head ){
    this->head = new N ( data );
    this->tail = head;
  }
  else{
    N *oldHead = this->head;
    this->head = new N ( data );
    this->head->next = oldHead;
    oldHead->prev = this->head;
  }
}

template <class T> void LinkedList<T>::append( T data )
{
#ifdef DEBUG
  cout << "In LinkedList<T>::append(...)\n";
#endif
  ++this->length;

  if ( !this->head ){
    this->head = new N ( data );
    this->tail = head;
  }
  else{
    N *newNode = new N ( data );
    this->tail->next = newNode;
    newNode->prev = this->tail;
    this->tail = newNode;
  }
}

template <class T> T  LinkedList<T>::set( int idx, T data )
{
#ifdef DEBUG
  cout << "In LinkedList<T>::set(...)\n";
#endif  
  N *n = getDLLNode( idx ); // Handles retieval and bound checks
  if ( !n ){
    return ( nullptr ); // Out of bounds
  }

  T *oldData = n.data;
  n.data = data;
  
  return ( oldData );
}

template <class T> T *LinkedList<T>::get( int idx )
{
  return &(getDLLNode( idx ))->data;
}

template <class T> T *LinkedList<T>::remAt( int idx )
{
#ifdef DEBUG
  cout << "In LinkedList<T>::remAt(...)\n";
#endif
  N *remMe = getDLLNode( idx );
  // Setting the sentinal to NULL would cause problems... so set the sentinal
  // to the previous link; if it's the head, set it to the head:
  if ( remMe == this->head ){
    this->sentinal = remMe;
  }
  else{
    this->sentinal = remMe->getPrev();
    --this->sIdx;
  }
  
  return rem( remMe );
}

template <class T> N *LinkedList<T>::getDLLNode( int idx )
{
#ifdef DEBUG
  cout << "In LinkedList<T>::getDLLNode(...)\n";
#endif
  if ( this->head == nullptr ){
#ifdef DEBUG
    cout << "\t-> Head null; returning nullptr\n";
#endif
    return nullptr;
  }
  if ( (this->length -1) < idx ){
#ifdef DEBUG
    cout << "\t-> Index > size; returning nullptr\n";
#endif
    return nullptr;
  }
  if ( idx < 0 ){
#ifdef DEBUG
    cout << "\t-> Index < 0; returning nullptr\n";
#endif
    return nullptr;
  }
  
  int curIdx = 0;
  N *cur = this->head;
  bool searchBackwards = false;
  
  // Check to see if the sentinal node is closer
  if ( this->sentinal != nullptr ){
#ifdef DEBUG
    cout << "\t-> Valid sentinal available; calculating sentinal distance from target\n";
#endif
    int sDist = 0;             // Distance sentinal is from index
    
    if ( ( sDist = ( idx - this->sIdx ) ) < 0 ){
      sDist = - sDist;
      searchBackwards = true;
#ifdef DEBUG
      cout << "\t-> Sentinal distance suggests reverse search; searchBackwards enabled\n";
#endif
    } 
   if ( sDist == 0 ){
#ifdef DEBUG
      cout << "\t-> Sentinal distance to target 0; returning sentinal\n";
#endif
      return sentinal;
    }
    
    // Check to see if sentinal is closer than head
    if ( sDist < ( ( this->length - 1 ) - ( ( this->length ) - 1 - idx )  ) ){
      cur = sentinal;
      curIdx = this->sIdx;
#ifdef DEBUG
      cout << "\t-> Sentinal closer to target than head; setting search start-node to sentinal\n";
#endif
    }
    else{
      if ( searchBackwards ){
#ifdef DEBUG
        cout << "\t-> Sentinal further from target than head; correcting possible invalid\n"
             << "\t-> searchBackwards value (setting to disabled)\n";
#endif
        searchBackwards = false;
      }
    }
    
    // Not searching from sentinal, AND it's faster to search from tail?
    if ( curIdx == 0 && idx > length/2 ){
#ifdef DEBUG
      cout << "\t-> Tail closer to target than both head and sentinal nodes;\n"
           << "\t-> Searching backwards from tail\n";
#endif
      cur = this->tail;
      curIdx = this->length - 1;
      searchBackwards = true;
    }

    if ( searchBackwards ){    // Searching backwards
#ifdef DEBUG
      cout << "\t-> Performing reverse search\n";
#endif
      for ( ; curIdx > idx; curIdx-- ) cur = cur->prev;
    }
    else{                       // Searching forwards
#ifdef DEBUG
      cout << "\t-> Performing forward search\n";
#endif
      for ( ; curIdx < idx; curIdx++ ) cur = cur->next;
    }
  }
  else{
    // No sentinal to search from - use calassical search method:
#ifdef DEBUG
    cout << "\t-> Invalid sentinal; failing over to calassical forward search\n";
#endif
    for ( ; curIdx < idx; curIdx++ ) cur = cur->next;
  }

#ifdef DEBUG
  cout << "\t-> Setting sentinal to last visited node\n";
#endif
  this->sIdx = idx;
  this->sentinal = cur;
  
  return cur;
}

template <class T> T *LinkedList<T>::rem( N *n )
{
#ifdef DEBUG
  cout << "In LinkedList<T>::rem(...)\n";
#endif
  if ( n == nullptr ) {
    return nullptr;
  }
  if ( n == this->head ){
    return pop();
  }
  if ( n == this->tail ){
    return popTail();
  }

  n->next->next = n->next;
  n->next->prev = n->prev;
  
  return n->data;
}

#endif
