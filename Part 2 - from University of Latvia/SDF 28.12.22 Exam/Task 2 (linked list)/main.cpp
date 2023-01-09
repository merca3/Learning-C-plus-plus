/******************************************************************************

2. A list of numbers is implemented as a single-linked list using nodes. 
The node is of type Node {int info; Node* next}. Node* listHead points to the first node in the list. 
Write the function deleteElement(Node* listHead) which delete the node with index (position) stored in the last element. 
Indexing of nodes starts with 0.
Example 1: {1,2,5,3,2} is transformed to {1,2,3,2}.
Example 2: {1,2,5,3,7} is not changed because there is no node with index (position) 7.


*******************************************************************************/
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

// functions push_back, printLinkedList and deleteLinkedList are taken from lectures code
void push_back(Node*&first, Node*&last, int val) {
    Node *p = new Node;
    p->info = val;
    p->next = NULL;
    if (first == NULL) {
        first = p;
        last = p;
    } else {
        last->next = p;
        last = p;
    }
}

void printLinkedList(Node*first) {
    Node *p = first;
    if (p == NULL) {
        cout << "*** List is empty ***" << endl;
        return;
    }
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteLinkedList(Node*&first) {
    Node *p = first;
    while (first != NULL) {
        p = first->next;
        delete first;
        first = p;
    }
}

void deleteElement(Node*&listHead) {
    Node *p = listHead;
    
    int lastElement;
    int index = 0;
    // finding size of list and value of last element
    while (p != NULL) {
        if (p->next == NULL) lastElement = p->info;
        p = p->next;
        index++;
    }
    int listSize = index;
    // cout << "Last element of single linked list: " << lastElement << endl;
    // cout << "Size of single linked list: " << listSize << endl;
    
    
    // doing actual removal of element, depending on its position
    p = listHead;
    if(lastElement == 0) { // if we need to delete first element
        listHead = listHead->next;
        delete p;
        
    } else if (lastElement > listSize - 1) { // if there is no such element
        cout << "-----------------------------" << endl;
        cout << "There is no node with index: " << lastElement << endl;
        
    } else if (lastElement == listSize -1) { // if we need to delete last element
        Node *c = p->next;  // c is next element after p
        while (c != NULL) {
            if (c->next == NULL) {
                p->next = NULL;
                delete c;
                break;
            }
            p = c;
            c = c->next;
        }
        
    } else { // if we need to delete element in the middle
        // p is first element in row
        Node *c = p->next;  // c is second element in row
        Node *n = c->next;  // n is third element in row
        index = 0;
        while (n != NULL) {
            ++index;
            if (index > 0 && index == lastElement) {
                p->next = n; // adding list from first to third element
                delete c;    // so middle (second) element can be deleted
                break;       // early loop break as needed element was deleted already
            }
            p = c;
            c = n;
            n = n->next;
        }
    }
}

int main()
{
    Node *listHead = NULL, *listTail = NULL;
    
    cout << "First example" << endl;
    // Creation of linked list
    push_back(listHead, listTail, 1);
    push_back(listHead, listTail, 2);
    push_back(listHead, listTail, 5);
    push_back(listHead, listTail, 3);
    push_back(listHead, listTail, 2);
    printLinkedList(listHead);
    deleteElement(listHead);
    printLinkedList(listHead); // expected {1,2,3,2}
    deleteLinkedList(listHead);
    
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Second example" << endl;
    
    push_back(listHead, listTail, 1);
    push_back(listHead, listTail, 2);
    push_back(listHead, listTail, 5);
    push_back(listHead, listTail, 3);
    push_back(listHead, listTail, 7);
    printLinkedList(listHead);
    deleteElement(listHead);
    printLinkedList(listHead); // no change expected
    deleteLinkedList(listHead);
}
