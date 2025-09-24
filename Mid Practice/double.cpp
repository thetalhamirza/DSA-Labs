#include <iostream>
using namespace std;

class Node {

    public:

    int value;
    Node* prev;
    Node* next;

    Node(int val)   {
        value = val;
        prev = nullptr;
        next = nullptr;
    }

};

class Double {

    Node* head;
    Node* tail;

    void copyHelper(const Double& copy) {
        Node* temp = copy.head;
        while (temp != nullptr) {
            insertAtEnd(temp->value);
            temp = temp->next;
        }
    }

    public:

    Double()    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr)    {
            head = tail = newNode;
        }   else    {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val)   {
        Node* newNode = new Node(val);
        if (head == nullptr)    {
            head = tail = newNode;
        } else  {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "List empty" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next; 
        }
    }

    void displayBackward() {
        if (head == nullptr)    {
            cout << "List empty" << endl;
            return;
        }
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->prev;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr)    {
            cout << "List Empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr)    {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;   
    }

    void deleteFromEnd() {
        if (head == nullptr)    {
            cout << "List empty" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail == nullptr)    {
            head = nullptr;
        }   else {
            tail->next = nullptr;
        }
        
        delete temp;
    }

    Double(const Double& copy)  {
        head = tail = nullptr;
        copyHelper(copy);
    }

    Double& operator=(const Double& copy) {
        if (this != &copy) {
            while (head != nullptr) {
                deleteFromBeginning();
            }
            copyHelper(copy);
        }
        return *this;
    }

    ~Double() {
        while (head != nullptr) {
            deleteFromBeginning();
        }
    }

};


int main() {
    Double list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    cout << "Forward display:" << endl;
    list.displayForward();

    cout << "Backward display:" << endl;
    list.displayBackward();

    list.deleteFromBeginning();
    cout << "After deleting from beginning (forward):" << endl;
    list.displayForward();

    list.deleteFromEnd();
    cout << "After deleting from end (forward):" << endl;
    list.displayForward();

    return 0;
}
