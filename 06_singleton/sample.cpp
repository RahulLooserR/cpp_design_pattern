// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Singleton
{
public:
    static Singleton& getInstance() { return instance; }
    int getValue() { return var; }

    // important to delete copy constructor to avoid making any copy
    Singleton(const Singleton&) = delete;

private:
    Singleton() {};
    static Singleton instance;
    int var = 5;
};

// important to define static member
Singleton Singleton::instance;


// we can have similar implementation using namespace
namespace SingleNamespace {
    int var = 10;
}

int main()
{
    Singleton& inst = Singleton::getInstance();
    int x = Singleton::getInstance().getValue();  // directly access variable without making instance
    int y = inst.getValue();
    SingleNamespace::var = 100;
   // Singleton intsance2 = inst;  error copy contructor deleted
    std::cout << inst.getValue() << "\n";
}
