//
//  Node.hpp
//  Assignment6
//
//  5/27/21.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
template <class S>
class Node {
public:
    struct ListNode {
        S value;
        struct ListNode *next = nullptr;
    };
};

#endif /* Node_hpp */
