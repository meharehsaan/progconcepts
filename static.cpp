#include <iostream>
using namespace std;

/*
    Static variables are declared out of class because we have to allocate them memory
    for their existance and whole class shared the variable created once not on every
    instance of class separately.
*/

class MyClass
{
public:
    static int sharedVariable;  // Declaration of the static variable
    static int count;          // This static variable will persist across function calls.

    void display()
    {
        std::cout << "Shared Variable: " << sharedVariable << std::endl;
    }

    void incrementAndPrint()
    {
        count++;
        std::cout << "Count: " << count << std::endl;
    }
};

// Initialization of the static variable outside the class
int MyClass::count = 0;
int MyClass::sharedVariable = 100;

int main()
{
    MyClass obj1, obj2;

    cout << MyClass::count << endl;

    obj1.incrementAndPrint(); // count 1
    obj1.incrementAndPrint(); // count 2
    obj1.incrementAndPrint(); // count 3

    obj1.display(); // Shared Variable: 100
    obj2.display(); // Shared Variable: 100

    // Modifying the shared variable through one of the instances
    obj1.sharedVariable = 200;

    obj1.display(); // Shared Variable: 200
    obj2.display(); // Shared Variable: 200

    return 0;
}

/*
    Static variables defined outside of the class are often used as class-level constants
    or shared data among all instances of the class. It's important to remember to define
    the static variable in one source file only; otherwise, you may encounter linker errors
    due to multiple definitions.
*/

/* 
    1. Retaining state across function calls Useful for counters, trackers, or maintaining state 
    information between calls to the same function.

    2. Sharing data across class instances Allows data to be shared among all objects of the class, 
    reducing memory consumption and improving data coherence.
 */