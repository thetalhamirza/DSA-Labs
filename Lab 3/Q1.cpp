#include <iostream>
using namespace std; 

class Node {
    public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
    
};

class Single {
    public:

    Node* head;
    Node* tail;

    Single() {
        head = NULL;            // points to the starting element
        tail = NULL;            // points to the ending element
    }

    ~Single() {
        Node* tempA = head;
        while (tempA != NULL)  {
            Node* tempB = tempA->next;
            delete tempA;
            tempA = tempB;
        }
        head = NULL;
        tail = NULL;
    }

    void first(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {                 // if no elements exist
            
            head = newNode;
            tail = head;
            newNode->next = NULL;
        
        }   else    {

            newNode->next = head;           // if elements exist and
            head = newNode;                 // we have to store at start
        
        }
    }

    void last(int data) {                   // add to last
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = tail->next;
    }

    void printList() {
        Node* temp = head;
        while (temp->next != NULL) {
            cout << temp->val << endl;
            temp = temp->next;
        }
        cout << temp->val << endl;
    }

    void sort() {
        if (head == NULL || head->next == NULL) {       // returns if no element or
            return;                                     // only one element
        }
        
        Node* evenHead = new Node(0);       // creating an even list
        Node* oddHead = new Node(0);        // and odd list
        Node* evenTail = evenHead;
        Node* oddTail = oddHead;
        Node* current = head;

        while (current != NULL) {
            if (current->val % 2 == 0) {            // even value goes to even list
                evenTail->next = current;           
                evenTail = evenTail->next;
            }   else    {
                oddTail->next = current;            // odd value goes to odd list
                oddTail = oddTail->next;
            }
            current = current->next;                // traversing current
        }

        evenTail->next = oddHead->next;               // concatenating even then odd lists respectively
        oddTail->next = NULL;                   // marking end to LL
        
            
        delete evenHead;
        delete oddHead;                 // memory freeing


    }
};

int main() {
    Single list;
    list.first(0);
    for (int i=1; i<=15; i++) {
        list.last(i);
    }
    
    cout << "Normal list: " << endl;
    list.printList();
    
    list.sort();
    
    cout << endl << "Sorted list: " << endl;
    list.printList();
}