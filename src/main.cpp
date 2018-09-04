#include <iostream>

#include "linkedlist.h"

int main(int argc, char** argv) {
    // create head node
    Node* front = new Node(0);

    // insert values 1-9 into list
    Node* nd = front;
    for(unsigned int i=1; i<10; i++) {
        nd = nd->push_back(i);
    }

    // loop over all nodes and get values out of them
    nd = front;
    while(nd != nullptr) {
        std::cout << nd->value << std::endl;
        nd = nd->next;
    }

    std::cout << "----------------" << std::endl;

    // insert at least five more sixes to obtain the right amount of sixes, i.e. 6
    for(unsigned int i=0; i<5; i++) {
        front->insert(6,6);
    }

    // loop over all nodes again
    nd = front;
    while(nd != nullptr) {
        std::cout << nd->value << std::endl;
        nd = nd->next;
    }

    std::cout << "----------------" << std::endl;

    // finally, output all node addresses to showcase that these nodes
    // are not continuous in memory
    std::cout << "The size of a node is " << sizeof(Node) << " bytes." << std::endl;
    nd = front;
    while(nd != nullptr) {
        std::cout << nd << std::endl;
        nd = nd->next;
    }

    return 0;
}
