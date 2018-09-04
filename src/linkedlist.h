#ifndef _NODE_H
#define _NODE_H

#include <stdexcept>

class Node {
public:
    int value;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int val) : value(val) {}

    Node* insert(int val, unsigned int nriter = 0) {
        Node* pos = this;
        for(unsigned int i=0; i<nriter; i++) {
            pos = pos->next;
            if(pos == nullptr) {
                std::cerr << "Invalid position, cannot insert new node past tail" << std::endl;
                exit(-1);
            }
        }

        Node* newnode = new Node(val);

        if(pos->next != nullptr) {
            newnode->next = pos->next;
            pos->next->prev = newnode;
        }

        pos->next = newnode;
        newnode->prev = pos;

        return newnode;
    }

    Node* push_back(int val) {
        Node* pos = this;

        // keep looping until tail is found
        while(pos->next != nullptr) {
            pos = pos->next;
        }

        return pos->insert(val);
    }
};

#endif // _NODE_H
