#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = prev = nullptr;
    }

};

class CircularDoublyLinkedList {

    private:
    Node* head;
    Node* tail;


    public:
    CircularDoublyLinkedList() {
        head = tail = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
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
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
    }

    void deleteNode(int value) {
        if (head == nullptr) return;

        Node* current = head;

        do {
            if (current->data == value) {
                if (current == head && current == tail) {
                    delete current;
                    head = tail = nullptr;
                    return;
                }
                if (current == head) {
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                    delete current;
                    return;
                }
                if (current == tail) {
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                    delete current;
                    return;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return;
            }
            current = current->next;
        } while (current != head);
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
};

int main() {
    CircularDoublyLinkedList numList;

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
