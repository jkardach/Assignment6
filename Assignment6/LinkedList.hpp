//
//  LinkedList.hpp
//  Assignment6
//
//  5/27/21.
//  This is a template class, so implementation in same file
//  This creates a linked list things
//  you can add, remove, insert, append, list, find and many other
//  useful things you wish to do with a list.
//  The list only contains a single value, but that value is a template
//  and can be anything (even a complex class object).

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
#include "Node.hpp"

using namespace std;
//#include "Node.hpp"

template <class T>
class LinkedList {
private:
////    Node;
//    struct Node {
//        T value;
//        struct Node* next = nullptr;
//    };
public:
    Node<T>* first = nullptr;
    Node<T>* last = nullptr;
    // constructors/deconstructors
    LinkedList():first(nullptr), last(nullptr) { }
    
    // copy constructor
    LinkedList(const LinkedList &obj) {

        if(!obj.first) {
            first = nullptr;
            last = nullptr;
            return;
        }
        // create first node, copy data over
        first = new Node<T>;               // create new node, first points to
        first->value = obj.first->value;  // copy data over
        Node<T>* nodePtr = first;          // create new pointer, points to first
        Node<T>* objPtr = obj.first;       // create new pointer to obj first
        
        // continue this process until objPtr next points to null
        while(objPtr->next) {
            nodePtr->next = new Node<T>;   // create new object
            nodePtr = nodePtr->next;    // increment nodePtr
            objPtr = objPtr->next;      // increment objPtr
            nodePtr->value = objPtr->value; // set value to new pointer
        }
        // comming out of this, objPtr points to last object
        last = nodePtr;
    }
    
    // destrutor
    ~LinkedList() {
        Node<T>* nodePtr = first;
        Node<T>* delPtr = nullptr;
        while(nodePtr) {
            delPtr = nodePtr;
            nodePtr = nodePtr->next;
            delete delPtr;
        }
        first = nullptr;
        last = nullptr;
    }
    
    // prints out the list
    void printList() const {
        Node<T>* nodePtr = first;
        while(nodePtr) {
            cout << nodePtr->value;
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }
    // adds a node to end of list
    void append(const T data) {
        Node<T>* newNode = new Node<T>();
        newNode->value = data;

        if(!first) {
            // empty list case
            first = newNode;
            last = newNode;
        } else {
            // add to end of list
            last->next = newNode;
            last = newNode;
        }
    }
    
    // adds a node to first of list
    void prepend(const T data) {
        Node<T>* newNode = new Node<T>();
        newNode->value = data;
        if(first) {
            newNode->next = first;
            first = newNode;
        } else {
            // empty list case
            first = newNode;
            last = newNode;
        }
    }
    
    // returns true if removes first
    bool removeFront() {
        if(!first) { return false; }  // if empty list, return
        Node<T>* delPtr = first;
        if(!first->next) {
            // only single node in list
            first = first->next;
            last = first->next;
        } else {
            // more than one node in list
            first = first->next;
        }
        delete delPtr;  // delete the first
        return true;
    }
    
    // inserts node in correct order (acending order)
    void insert(const T data)  {
        Node<T>* newNode = new Node<T>();
        newNode->value = data;
        if(!first) {
            // no nodes, make new node first and last
            first = newNode;
            last = newNode;
            return;
        }
        // one or more nodes
        Node<T>* nodePtr = first;          // nodePtr at beginning of list
        Node<T>* previousNode = nullptr;   // previous node to nullptr
        // skip all nodes whose value is less than num.
        while(nodePtr != nullptr && nodePtr->value < data) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // if new node is to be the 1st in the list, insert it before all others
        if(previousNode == nullptr) {
            first = newNode;
            newNode->next = nodePtr;
        } else {
            // else insert after previousNode
            previousNode->next = newNode;
            newNode->next = nodePtr;
            if(previousNode == last) {
                // if last, then reset last
                last = previousNode->next;
            }
        }
    }
    
    // true if removes node of value data
    bool remove(const T data) {
        if(!first) { return false;}   // no nodes, return
        Node<T>* nodePtr = first;
        if(first->value == data) {
            // see if this is the first guy
            nodePtr = first->next;
            delete first;
            first = nodePtr;
            return true;
        }
        // else find and delete node
        Node<T>* previousNode = nullptr;
        
        while(nodePtr != nullptr && nodePtr->value != data) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr) {
            previousNode->next = nodePtr->next;
            if(last == nodePtr) {
                last = previousNode;  // reset last if last
            }
            delete nodePtr;
            return true;
        }
        return false;
    }
    
    // true if item is in list
    bool find(const T data) {
        
        if(!first) {
            // no nodes
            return false;
        }
        // more than one node now
        bool match = false;
        Node<T>* nodePtr = first;
        while(nodePtr) {
            
            if(nodePtr->value == data) {
                match = true;
                break;
            } else {
                nodePtr = nodePtr->next;
            }
        }
        return match;
    }
    
    // true if list is empty
    bool isEmpty() const {
        return !first;
    }
    
    // returns value stored in first node
    T getFirst() const {
        return first->value;
    }
    
    // returns value stored in last node
    T getLast() const {
        return last->value;
    }
    
};

#endif /* LinkedList_hpp */
