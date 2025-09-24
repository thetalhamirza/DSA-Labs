#include <iostream>
using namespace std;

class Node {
    public:
    
    int value;
    Node* next;
    
    Node(int v) {
        value = v;
        next = nullptr;
    }
};


class CircularSingle {

    Node* head;
    Node* tail;

    public:

    CircularSingle() {
        head = nullptr;
        tail = head;
    }


    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr)    {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    
    void insertAtEnd(int val)   {
        Node* newNode = new Node(val);
        if (head == nullptr)    {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

    }

    void display() const {
        if (head == nullptr) {
            cout << "List empty" << endl;
            return;
        }
        Node* temp = head;
        cout << temp->value << endl;
        temp = temp->next;
        while (temp != head) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        if (head == nullptr) {
            tail = nullptr;
            return;
        }

        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        } 
        delete tail;
        tail = temp;
        tail->next = head;
    }

    CircularSingle(const CircularSingle& copy)  {
        head = tail = nullptr;
        Node* temp = copy.head;
        insertAtEnd(temp->value);
        temp = temp->next;
        while (temp != copy.head) {
            insertAtEnd(temp->value);
            temp = temp->next;
        }
    }

    
    CircularSingle& operator=(const CircularSingle& copy)   {
        if (this != &copy)  {
            while (head != nullptr) {
                deleteFromBeginning();
            } 
            Node* temp = copy.head;
            insertAtEnd(temp->value);
            temp = temp->next;
            while (temp != copy.head) {
                insertAtEnd(temp->value);
                temp = temp->next;
            }
        }
        return *this;
    }


    // destructor
    ~CircularSingle() {
        while (head != nullptr) {
            deleteFromBeginning();
        }
    }
};


int main() {
    CircularSingle list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    cout << "List after inserts:" << endl;
    list.display();

    list.deleteFromBeginning();
    cout << "After deleting from beginning:" << endl;
    list.display();

    list.deleteFromEnd();
    cout << "After deleting from end:" << endl;
    list.display();

    return 0;
}
