/*******************************************************************************
 * Class: dllNode (doubly linked list node)
 * Author: Quin J. G. Rider
 * Date of creation: 2018-03-13
 * Last Modified: 2019-03-25
 *
 * Purpose: Data wrapper for use in a doubly linked list
 *
 * Functions:
 *   + dllNode( T ) -> Constructor
 * 
 * Variables:
 *   + T data
 *   + dllNode *next;
 *   + dllNode *prev;
 * 
 ******************************************************************************/

// Forward declaration so that LinkedList<T> can be friended
template <class T> class LinkedList;


template <class T> class DLLNode
{
public:
  DLLNode<T>( T );
  
  DLLNode *getNext();
  DLLNode *getPrev();
  
  void setNext( DLLNode * );
  void setPrev( DLLNode * );
  
  T getData();
  
private:
  friend class LinkedList<T>;

  DLLNode *next;
  DLLNode *prev;
  T data;
};

template <class T> DLLNode<T>::DLLNode( T data )
{
  next = nullptr;
  prev = nullptr;
  this->data = data;
}

template <class T> DLLNode<T> *DLLNode<T>::getNext()
{
  return next;
}

template <class T> DLLNode<T> *DLLNode<T>::getPrev()
{
  return prev;
}
  
template <class T> void DLLNode<T>::setNext( DLLNode *n )
{
  next = n;
}

template <class T> void DLLNode<T>::setPrev( DLLNode *p )
{
  prev = p;
}

template <class T> T DLLNode<T>::getData()
{
  return data;
}
