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


class Single {

    Node* head;
    Node* tail;

    public:

    Single() {
        head = nullptr;
        tail = nullptr;
    }


    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr)    {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    
    void insertAtEnd(int val)   {
        Node* newNode = new Node(val);
        if (head == nullptr)    {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

    }

    void display() const {
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

    void deleteFromBeginning() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
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
        tail->next = nullptr;
    }

    void linearSearch(int val)  {
        int index = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (val == temp->value) {
                cout << "Element found at index: " << index << endl;
                return;    
            }   else    {
                index++;
                temp = temp->next;
            }
        }
        cout << "Element not found." << endl;
    }

    // void recursiveInsertion(int value, Node* current) {
    //     Node* forward = current->next;
    //     while (current!=nullptr)    {
    //         if (forward == )
    //     }
    // }



    Single(const Single& copy)  {
        head = tail = nullptr;
        Node* temp = copy.head;
        while (temp != nullptr) {
            insertAtEnd(temp->value);
            temp = temp->next;
        }
    }

    
    Single& operator=(const Single& copy)   {
        if (this != &copy)  {
            while (head != nullptr) {
                deleteFromBeginning();
            } 
            Node* temp = copy.head;
            while (temp != nullptr) {
                insertAtEnd(temp->value);
                temp = temp->next;
            }
        }
        return *this;
    }


    // destructor
    ~Single() {
        while (head != nullptr) {
            deleteFromBeginning();
        }
    }
};


int main() {
    // Single list;

    // list.insertAtEnd(10);
    // list.insertAtEnd(20);
    // list.insertAtBeginning(5);
    // list.insertAtEnd(30);

    // cout << "List after inserts:" << endl;
    // list.display();

    // list.deleteFromBeginning();
    // cout << "After deleting from beginning:" << endl;
    // list.display();

    // list.deleteFromEnd();
    // cout << "After deleting from end:" << endl;
    // list.display();

    // ----------------------------------------------------

    // Single list;
    // list.insertAtEnd(10);
    // list.insertAtEnd(20);
    // list.insertAtEnd(30);

    // list.linearSearch(20);  // → Element found at index: 1
    // list.linearSearch(40);  // → Element not found.

    // ----------------------------------------------------



    return 0;
}
