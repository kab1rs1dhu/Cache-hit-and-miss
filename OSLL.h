/* Ordered Set Implemented in a Doubly-Linked List */
// File: OSLL.h

#include <iostream>
#include <cstring>
using namespace std;


template <typename T> 
class OSLL
{
public:
   OSLL()
   {
      // make the front and back dummy nodes 
      front = new Node( T(), nullptr, nullptr);
      back = new Node( T(), front,nullptr);
      front->next = back;

      size = 0 ;
   }

   ~OSLL()
   {
      Node * cursor = front ;
      while( cursor != nullptr )
      {
         Node * current = cursor ;
         cursor = cursor-> next ;
         delete  current ;
      }
   }
   bool isEmpty()
   { 
      return size==0 ;
   }

   int get_size()
   { 
      return size ;
   }

   bool insert(T item)
   { 
      Node * cursor = front-> next ;
      while( cursor->data < item && cursor != back )
      {
         cursor = cursor-> next ;
      }

      if( cursor -> data != item )
      {
         Node *n = new Node(item , cursor->prev , cursor); // the constructor takes care of half the links
         cursor->prev->next = n;
         cursor->prev = n;
         size ++;
         return true;
      }

      else
      {
         return false ; // return false if the item was already in the linked list
      }
   }


   bool find(T item)
   {

      Node * cursor = front-> next ;
      while( cursor->data < item && cursor != back )
      {
        cursor = cursor->next;
      }
      return ( cursor->data == item);
   }


   bool remove(T item)
   { 

      Node * cursor = front-> next ;
      while( cursor->data < item && cursor != back )
      {
         cursor = cursor-> next ;
      }
      if( cursor == back  || cursor->data > item )
      { 
         // The item is not in the list 
         return false ; 
      }
      else
      {
         cursor->prev->next = cursor->next;
         cursor->next->prev = cursor->prev; // takes care of the links both the ways
         delete cursor;
         size -- ;
         return true ;
      }
   }

   T getMin()
   {
     // returns the minimum item in the list
     // requires: size > 0 
     return front->next->data ; 
   } 

   T getMax()
   { 
      // returns the maximum item in the list 
      // requires: size > 0
      return back->prev->data ; 
   }

   void display()
   {
      Node * cursor = front-> next ;
      cout << "<" ;
      while( cursor != back ){
         cout << " " << cursor-> data ;
         cursor = cursor-> next ;
      }
      cout << " >" ;
      cout << endl;
   }

      
private:

   class Node
   {
      public: 
      Node( T data, Node* prev, Node* next )
      {
         // notice that the constructor argruments do most of 
         // the work of linking a new node into the list 
         this->data = data ;
         this->prev = prev ;
         this->next = next ;
      }
      Node * prev ;
      Node * next ;
      T data ;
   };

   int size ; // current number of items 
   Node * front ; 
   Node * back ;
};
