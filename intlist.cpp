// intlist.cpp
// Implements class IntList
// Katelyn Hamel, 4/6/26

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
   Node * obj = head;
   Node* currS = source.head;

   while(!(currS == NULL)){
    obj->info = currS->info;
    obj->next = currS->next;

    obj = obj->next;
   }


}
    

// destructor deletes all nodes
IntList::~IntList() {
    while (!(head == NULL)){
        Node* curr = head;
        head = head->next;

        delete curr;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = head;

    while (!(curr == NULL)){
        sum += head->info;

        curr = curr->next;
    }

    
    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while (!(curr == NULL)){
        if (curr->info == value)
            return true;

        curr = curr->next;
    }
    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* curr = head;

    int maxVal = 0;
    
    while (!(curr == NULL)){
        if (curr->info > maxVal)
            maxVal = curr->info;
        

        curr = curr->next;
    }

    return maxVal; // REPLACE THIS NON-SOLUTION

}
    


// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int count = 0;
    double sum = 0.0;
    Node* curr = head;

    while (!(curr == NULL)){
        sum+= curr->info;
        count++;
        curr = curr->next;

    }

    return  (sum/count);// REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNodePtr = new Node;
    newNodePtr->info = value;
    newNodePtr->next = head;
    head = newNodePtr;

    
    // IMPLEMENT
}

// append value at end of list
void IntList::push_back(int value) {
    Node* curr = head;
    Node* newNodePtr = new Node;
    //making the new tail
    newNodePtr->info = value;
    newNodePtr->next = NULL;
    

    //traversing to the end of the linked list so I can connect
    while (!(curr->next == NULL)){
        curr = curr->next;
    }
    //connecting the new tail to the rest of list
    curr->next = newNodePtr;
    tail = newNodePtr;
 
}

// return count of values
int IntList::count() const {
   int count = 0;
   Node* curr = head;

   while (!(curr == NULL)){
        count++;
        curr = curr->next;
   }

   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    
}

// constructor sets up empty list
IntList::IntList(){ 
    head = NULL;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

