#include "OSLL.h"
using namespace std;
#include <iostream>
#include <cstdlib>
#include <chrono>



int main()
{

    srand(time(0));
    OSLL <int> osll_1;

    cout << "Trying to insert some items " << endl;
    for(int i=200; i>=0; i--) // does head insert every time
    {
        osll_1.insert(i);
    }

    cout << "The OSLL is " << endl;
    osll_1.display();
    cout << endl;

    cout << "The minimum node is " << osll_1.getMin() << endl << endl;
    cout << "The maximum node is " << osll_1.getMax() << endl << endl;

    cout << "Trying to remove some items " << endl; // removing a substatial amount to test the steal and merging of nodes 
    for(int i=0; i<100; i++)
    {
        osll_1.remove(rand() % 100); // removes 100  items from the doubly linked list
    }

    cout << "After removing some items , the OSLL is " << endl; // prints the linked list after removing some elements 
    osll_1.display();
    cout << endl;

    cout << "The minimum number is " << osll_1.getMin() << endl; // displays the min and max numbers in the doubly linked list by printing the item in first node and last node as elements are in increasing order
    cout << "The maximum number is " << osll_1.getMax() << endl;
    cout <<  "The total number of nodes in this linked list are " << osll_1.get_size() << endl << endl;

    cout << "Trying to find some items " << endl;
    for(int i=0; i<100; i++)
    {
        int number = rand() % 100;
        cout << "Finding number = " << number;
        if(osll_1.find(number))
            cout << "   FOUND " << endl << endl;
        else
            cout<<  "   NOT FOUND " << endl << endl;
    }

     cout << "The number of nodes in OSLL are " << osll_1.get_size() << endl << endl;

     cout << "Trying to make a new list of characters " << endl << endl;

     OSLL <char> osll_2;

     osll_2.insert('d');
     osll_2.insert('c');
     osll_2.insert('e');
     osll_2.insert('a');
     osll_2.insert('b');
     osll_2.insert('c');

     cout << "The character list is " << endl << endl;
     osll_2.display();

     cout << "The max of the list is " << osll_2.getMax() << endl;
     cout << "The min of the list i " << osll_2.getMin() << endl;

     cout << "Trying to remove some characters " << endl;
     osll_2.remove('a');
     osll_2.remove('e');

     cout << "After removing some characters , the list is " << endl;
     osll_2.display();


     cout << endl;
     cout << "Done " << endl << endl;
     



}