//
//  Node.hpp
//  Assignment6
//
//  5/27/21.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
template <class T>
class Node {
public:
    T value;
    Node* next = nullptr;
};

#endif /* Node_hpp */
