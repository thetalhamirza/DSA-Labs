#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class Single
{
public:
    Node *head;
    Node *tail;

    Single()
    {
        head = NULL;
        tail = NULL;
    }

    void first(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        }    
    }

    void last(int val) {
        Node* newNode = new Node(val);
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        } 
        temp->next = newNode;
        newNode->next = tail;
    }

    Node* find(int search) {
        Node* temp = head;
        int count = 0;
        while (temp->val != search) {
            temp = temp->next;
            count++;
        }
        cout << "Node hops: " << count << endl;
        return temp;
    }

    void printList() {
        Node* temp = head;
        while (temp->next != NULL) {
            cout << temp->val << endl;
            temp = temp->next;
        }
        cout << temp->val << endl;
    }

    void addAfterIndex(int data, int index) {
        Node* temp = head;
        while (index >= 0) {
            temp = temp->next;
            index--;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode() {
        Node* newTemp = head;
        Node* temp = newTemp;
        newTemp = newTemp -> next;
        while (newTemp->next != tail) {
            temp = newTemp;
            newTemp = newTemp->next;
        }
        temp->next = tail;
        delete newTemp;

    }
};


int main() {
    Single list;
    list.first(10);
    list.last(20);
    for (int i=0; i<=30; i++) {
        list.last(i);
    }
    
    list.printList();
    // list.find(35);
    list.deleteNode();
    list.deleteNode();
    list.deleteNode();
    list.printList();
}