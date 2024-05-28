/* Ordered Set Implemented in an Unrolled (Doubly)-Linked List */
// File: OSULL.h

#include <iostream>
#include <cstring>
using namespace std;


template <typename T, int initNodeCapacity = 10 > 
class OSULL
{
public:
   OSULL()
   {

      // set the node capacity  
      nodeCapacity = initNodeCapacity ;

      // make the front and back dummy nodes 
      front = new Node( nullptr, nullptr, nodeCapacity );
      back = new Node( front, nullptr, nodeCapacity );
      front->next = back;

      size = 0 ;
      nodeCount = 0 ; 
   }
   ~OSULL()
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

    Node* cursor = front->next;
    while (cursor != back ) 
    {
         if(cursor->find(item))
            return false;

         else if ((cursor->getMin() < item && cursor->getMax() > item) ||(item < cursor->getMin()) ||  ((item > cursor->getMax() && cursor->next->getMin() > item)) || (item > cursor->getMax() && cursor->next == back))
            {
               break;
            } 
        cursor = cursor->next;
    }


       // returns false if item is already present in the OSULL

    if(cursor->getSize() < cursor->getCapacity())
   {

      if(nodeCount == 0) 
      {
         Node* temp = new Node(front,back,nodeCapacity);
         back->prev->next = temp;
         back->prev = temp;
         temp->insert(item);
         nodeCount++; // increases node count as a new node has been created
         this->size++; // increases the size
      }

      else
      {
         cursor->insert(item);
         this->size ++; // takes count of the total number of elements in the unrolled linked list
      } 
   }
   else 
   {
      Node* newNode = new Node(cursor, cursor->next, nodeCapacity);
            cursor->next->prev = newNode; // Connect the next node's prev pointer to the new node
            cursor->next = newNode; // Connect the current node's next pointer to the new node

            int size = cursor->getSize();

            for (int i = size / 2; i < size; i++) 
            {
               cursor->size --;
               newNode->insert(cursor->data[i]);
            }
            nodeCount ++;
           if((item > cursor->getMin() && item < cursor->getMax()) || (item < cursor->getMin()))
           {
               cursor->insert(item);
               this->size ++;
           }
            else
            {  
               newNode->insert(item);
               this->size ++;

            }
               
   }

   return true;

}


    bool find(T item)

   { 
        Node * cursor=this->front->next;
        while(cursor!=back)
        {
            //if(cursor->getMax()>=item) // checks if the max value of the cursor is less than or equal to item
            //{
                if(cursor->find(item))
                {
                    return true;
                }
                //return false;
            //}
            cursor=cursor->next;

        }
        return false;
   }

   bool remove(T item)
   {

      if( !find(item))
         return false;

      Node *cursor = front->next;
      while (cursor != back && cursor->getMax() < item)
      {
         cursor = cursor->next; // cursor is the node where we have to do the removal
      }

      cursor->remove(item); // removes item from cursor
      this->size--;


      if (cursor->getSize() < cursor->getCapacity()/2  && cursor->prev->getSize() > cursor->getCapacity()/2 && cursor->prev != front)
      {
         // if the size of cursor is less than 5 ( it will always be == 4in this case ) and the prev node size is > 5 provided
         // it is not the front node , it will STEAL one item from the prev node 

         Node* temp2 = cursor->prev;
         cursor->insert(temp2->data[temp2->getSize() -1]);
         temp2->remove(temp2->data[temp2->getSize() - 1]);
      }

      else if ((cursor->getSize() < cursor->getCapacity()/2 && cursor->prev->getSize() <= cursor->getCapacity()/2) && cursor->prev != front) // if cursor is the last node then the merge has to happen with the previous node
      {
         // if the size of cursor is less than 5 and the size of prev node is <= 5 , the  
         Node *PrevNode =  cursor->prev;

         for(int i=0 ; i<cursor->getSize(); i++)
         {
            PrevNode->insert(cursor->data[i]);
         }

         // updating the nodes so that all elements of cursor will go to prevnode and cursor will be deleted

         PrevNode->next = cursor->next;
         cursor->next->prev  = PrevNode;
         delete cursor;
         nodeCount --;

      }
      else if (cursor->getSize() < cursor->getCapacity()/2 && cursor->next->getSize() <= cursor->getCapacity()/2 && cursor == front->next && cursor->next != back)
      {
         Node* nextNode = cursor->next;

         // Transfer data from the next node to the current node
         for (int i = 0; i < nextNode->getSize(); i++)
         {
         cursor->insert(nextNode->data[i]);
         }

         // Update pointers to remove the next node from the list
         nextNode->prev->next = nextNode->next;
         nextNode->next->prev = nextNode->prev;


         // Delete the next node and update node count
         delete nextNode;
         --nodeCount;
      }

      else if(cursor->getSize() < cursor->getCapacity()/2 && cursor->next->getSize() > cursor->getCapacity()/2 && cursor == front->next && cursor->next != back)
      {
         Node *temp1 = cursor->next;
         cursor->insert(temp1->data[0]); // insert the first element of the 2nd node to front node
         temp1->remove(temp1->data[0]); // remove the first element from the 2nd node
      }

    return true;


   }

   T getMin()
   {
      return this->front->next->getMin();
   } 

   T getMax()
   {
      return this->back->prev->getMax();
   }

   void display()
   {
      Node * cursor = front-> next ;
      cout << "<" ;
      while( cursor != back )
      {
         cursor -> display() ;
         cursor = cursor-> next ;
      }
      cout << " >" ;
   }

 
private:

   class Node
   {
      public: 
      Node( Node* prev, Node* next, int capacity )
      {
         this->prev = prev ;
         this->next = next ;
         this->capacity = capacity ;
         data = new T[capacity] ;
         size = 0 ;
      }
      
      Node * prev ; // pointer to the next node 
      Node * next ; // pointer to the previous nodes 
      int capacity ; // capacity of this node 
      T * data ; // array of data items in this node 
      int size ; // current number of items in this node 

      int getCapacity()
      {
         return capacity; 
      }

      int getSize()
      {
         return size; 
      }

      T getMin()
      {
         if(this->size > 0)
         {
            return this->data[0] ; 
         }

         else
         {
            return 0;
         }
         
      }

      T getMax()
      {
         if(this->size > 0)
         {
            return this->data[size-1] ;
         }

         else
         {
            return 0;
         }
          
      }

      bool insert(T item)
      {

         if (size < this->capacity)    
         {
         
            if(this->find(item))
               return false;
         
            int i = 0;
            while (i < this->size && this->data[i] < item)
            {
               i++;
            }

            for (int j = this->size; j > i; j--)
            {
               this->data[j] = this->data[j - 1];
            }

     
            this->data[i] = item;
            this->size++;

            return true;
         }
      
        else
        {
            // Node is full, cannot insert the item
            return false;
        }
      }
      

      bool find(T item)
      {
         for(int i=0; i<this->size; i++)
         {
            if(this->data[i] == item)
               return true;
         }
         return false;
      }

      bool remove(T item)
      {
         int i = 0;

         while (i < size && data[i] != item)
         {
            i++; // i will be the correct index
         }

         if (i == size)
            return false; // Item not found

         for (int j = i; j < size - 1; ++j)
         {
            data[j] = data[j + 1];
         }

         size--;
         return true;

      }

      void display()
      {
         int i=0;
         while(i<this->getSize())
         {
            cout << this->data[i] << " "; // displays the elements in the node
            i++;
         }
      }


   };

   int size ; // current number of items 
   int nodeCount ; // current number of nodes 
   int nodeCapacity ; // capacity to assign to new nodes 
   Node * front ; // pointer to front dummy node 
   Node * back ;  // pointer to back dummy node 
};
