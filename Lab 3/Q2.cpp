#include <iostream>
using namespace std;

class Node {

public:
    
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {

    private:
    Node* head;
    Node* tail;


    public:

    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtPos(int value, int pos) {
        if (pos == 1) {
            insertAtStart(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
    }

    void deleteNode(int value) {
        if (head == nullptr) return;
        if (head->data == value) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                return;
            }
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }
        Node* current = head->next;
        Node* prev = head;
        while (current != head && current->data != value) {
            prev = current;
            current = current->next;
        }
        if (current->data == value) {
            prev->next = current->next;
            if (current == tail) tail = prev;
            delete current;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~CircularLinkedList() {
    if (head == nullptr) return;

    Node* current = head;
    Node* temp = current;
    current = current->next;
    delete temp;

    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    }

};

int main() {

    CircularLinkedList numList;

    numList.insertAtEnd(10);
    numList.insertAtEnd(20);
    numList.insertAtEnd(30);
    
    numList.printList();
    
    numList.insertAtStart(5);
    
    numList.printList();
    
    numList.insertAtPos(15, 3);
    
    numList.printList();
    
    numList.deleteNode(20);
    
    numList.printList();
    
    return 0;
}
