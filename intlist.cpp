// intlist.cpp
// Implements class IntList
// Katelyn Hamel, 4/6/26

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    
    head = NULL;

    
    Node* currS = source.head;

    if (currS == NULL)
        return;


    head = new Node;
    head->info = currS->info;
    head->next = NULL;

    Node* currObj = head;

    head->info = currS->info;

   while(!(currS->next == NULL)){
        currObj->next = new Node;
        currObj = currObj->next;

        currObj->info = currS->next->info;
        currObj->next=NULL;

        currS = currS->next;
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
        sum += curr->info;

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
    if (head == NULL)
        return 0;

    Node* curr = head;

    int maxVal = head->info;
    
    while (!(curr->next == NULL)){
        if (curr->info > maxVal)
            maxVal = curr->info;
        

        curr = curr->next;
    }

    return maxVal; // REPLACE THIS NON-SOLUTION

}
    


// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == NULL)
        return 0.0;

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

    if (head == NULL){
        head = newNodePtr;
        tail = newNodePtr;
        return;
    }
    

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
    if (this == &source){
        return *this;
    }
    
    Node* oldThis = head;
     Node* currS = source.head;

    //deleting the old list of nodes
    while (!(oldThis == NULL)){
        Node* temp = oldThis;
        oldThis = oldThis->next;
        delete temp;

    }


    head = NULL;

    if (currS == NULL)
        return *this;

    
    head = new Node;
    head->info = currS->info;
    head->next = NULL;
    Node* currObj = head;
   

    while (!(currS->next == NULL)){
        currObj->next = new Node;
        currObj = currObj->next;

        
        currObj->info = currS->next->info;
        currObj->next = NULL;

        currS = currS->next;
        

    }


    return *this;
    
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

