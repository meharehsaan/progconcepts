/*
 * The Singleton pattern is a creational design pattern that ensures a class has only one instance
 * and provides a global point of access to it. The purpose of the Singleton pattern is to control 
 * object creation, limiting the number of instances to exactly one, and providing a single point 
 * of access to that instance.
 */

#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;       //declaration
    static int count;
    
    //contructor
    Singleton() {
        count++;
        std::cout << "Instance " << count << " created." << std::endl;
    }
    
public:

    static Singleton* getInstance() {            //return type object
        if (count < 3) {
		std::cout << "Created object successfully :) " << std::endl;
            instance = new Singleton();
        }else{
		std::cout << "Cannot create object limit got full :( " << std::endl;
		instance = nullptr;
	}
        return instance;                        //returns object of this class
    }
    
    static void destroyInstance() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }
    
    void printMessage() {
        std::cout << "Hello from Singleton! I am the object" << std::endl;
    }
};

/*
 * To allocate memory for static member variables and provide their initial values, 
 * you need to define and initialize them outside the class, typically in a source file.
 */

Singleton* Singleton::instance = nullptr;       //static instance initialization
int Singleton::count = 0;                      //static count var initialization

int main() {

    Singleton* obj1 = Singleton::getInstance(); //calling static function to get object
    //obj1->printMessage();

    Singleton* obj2 = Singleton::getInstance();
    //obj2->printMessage();
    
    Singleton* obj3 = Singleton::getInstance();
    //obj3->printMessage();
    
    Singleton* obj4 = Singleton::getInstance();
    if (obj4 == nullptr) {
        std::cout << "Cannot create more than three instances." << std::endl;
    }
    
    Singleton::destroyInstance();          //destroying objects
    Singleton::destroyInstance();
    Singleton::destroyInstance();
    //Singleton::destroyInstance();
    
    return 0;
}

/*
 * The Singleton pattern is commonly used in scenarios where having multiple instances of a class 
 * could cause issues, such as managing resources, database connections, logging, or configuration
 * settings. By enforcing a single instance, the Singleton pattern provides a central point of 
 * control and avoids duplication or conflicts.
 */
