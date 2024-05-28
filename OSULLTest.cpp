#include "OSULL.h"
#include <iostream>
#include <cstring>
using namespace std;



int main() 
{
    OSULL<int> osull;
    //srand(time(0));

    for(int i=0; i<80; i++)
    {
        int random = rand() %100;
        cout << "INSERTING " <<  random << endl;
        osull.insert(random);
        cout << "DISPLAY : " << endl;
        osull.display(); // using ddiplay to show the splitting of nodes
        cout << "Element count for the above node is " << osull.get_size() << endl;
        cout << endl;
        cout << endl;
    }

    cout << "Element count = " << osull.get_size() << endl << endl;

    cout << "DISPLAY : " << endl;
    osull.display();
    cout << endl;

    cout << endl;
    cout << "The max element is " << osull.getMax() << endl;
    cout << "The min element is " << osull.getMin() << endl;
    cout << endl;
    cout << endl;

    cout << "Number of elements  = " << osull.get_size() << endl;

    
    for(int i=0; i<20; i++)
    {
        int random = rand() %200;
        if(osull.find(random))
            cout <<  random << " Found " << endl;                      
        else
            cout << random << " Not found " << endl;
    }
    cout << endl;
    cout << "removing some numbers to test steal of node " << endl;
    osull.remove(21);
    
    cout << "DISPLAY :" << endl;
    osull.display();
    cout << endl;

    cout << "Removing 22" << endl;
    cout << "Tests stealing of node" << endl;
    osull.remove(22);
    osull.display(); // steals node properly


    cout << endl;
    cout << "tests merging of nodes " << endl;
    cout << "Removing some numbers to test the merge function " << endl; // it merges with the prev node as the size of the prev node is == 5
    osull.remove(49);
    osull.remove(50);
    osull.remove(36);
    osull.remove(37);
    cout << "DISPLAY : " << endl;
    osull.display();
    cout << endl <<endl;

    cout << "Removing 35" << endl;
    cout << "Merges two nodes " << endl;
    osull.remove(35);
    osull.display();
    cout << endl << endl;
    cout << "The number of elements are " << osull.get_size() << endl << endl;

    cout << endl;

    cout << "Making a new character OSULL on the heap " << endl;
    OSULL <char> *osull_1 = new OSULL <char>;
    for(int i=0; i<20; i++)
    {
        osull_1->insert('a' + rand() %26);
    }

    osull_1->display();
    cout << endl;
    cout << "The size of the character unrolled linked list is " << osull_1->get_size() << endl << endl;

    cout << "Trying to find some characters " << endl;
    for(int i=0; i<30; i++)
    {
        char random = 'a' + rand() % 20;
        if(osull_1->find(random))
            cout << random << " Found " << endl;
        else
            cout << random << " Not found " << endl;
    }
    cout << endl << endl;

    cout << "The min character in the list = " << osull_1->getMin() << endl;
    cout << "The max character in the list = " << osull_1->getMax() << endl;



    cout << "Trying to remove some items " << endl;
    for(int i=0; i<10; i++)
    {
        char random = 'a' + rand() % 20;
        cout << "REMOVING " << random <<endl;
        osull_1->remove(random);
    }

    cout << "After removing some items , the characater list is " << endl;
    osull_1->display();

    cout << "The min character in the list = " << osull_1->getMin() << endl;
    cout << "The max character in the list = " << osull_1->getMax() << endl;

    cout << "Deleting the character list" << endl;
    delete osull_1;
    cout << endl << endl;
    cout << "Done " << endl;

}
