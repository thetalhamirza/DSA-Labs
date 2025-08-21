#include <iostream>
using namespace std;

class Box {
    int *value;

    public:

    // Constructor
    Box(int v = 0) {
        value = new int(v);
    }

    // Destructor
    ~Box() {
        delete value;
    }

    // Copy Constructor (Deep Copy)
    Box(const Box& copy) {
        value = new int(*copy.value);
    }

    // Copy Assignment Operator 
    Box operator=(const Box& copy) {
        if (this != &copy) {
            delete value;
            value = new int(*copy.value);
        }
        return *this;
    }

    // Getter Setter

    int getValue() const { return *value; }
    void setValue(int v) { *value = v; }
};

// Demonstrating Problematic Class with Shallow Copy

class shallowBox {
    int *value;

    public:

    // Constructor
    shallowBox(int v = 0) {
        value = new int(v);
    }

    // Destructor
    ~shallowBox() {
        delete value;
    }

    // Getter Setter

    int getValue() const { return *value; }
    void setValue(int v) { *value = v; }

    // No copy constructor or copy assignment operator
};


int main() {

    // Deep Copy

    Box box1(82);
    Box box2 = box1;

    // couting values

    cout << box1.getValue() << endl;
    cout << box2.getValue() << endl;
    
    // Changing box2's value
    
    box2.setValue(54);
    
    // couting values

    cout << box1.getValue() << endl;
    cout << box2.getValue() << endl;
    
    // Only box2 value is changed   
    
    Box box3;
    box3 = box1;
    cout << box3.getValue() << endl;
    

    // Shallow Copy

    shallowBox shallow1(25);
    cout << shallow1.getValue() << endl;
    
    shallowBox shallow2 = shallow1;
    cout << shallow2.getValue() << endl;
    
    // Modifying shallow2

    shallow2.setValue(50);

    // checking shallow 2

    cout << shallow2.getValue() << endl;
    
    // checking shallow 1

    cout << shallow1.getValue() << endl;

    // Value of shallow1 also changes upon changing value of shallow2
    // Same destructor issue when both objects try to delete the same memory location
}