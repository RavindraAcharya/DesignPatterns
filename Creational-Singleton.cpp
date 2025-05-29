// Creational-Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
private : 
    Singleton() { "Singleton Instance is created now "; }
    static Singleton* instance;
    static std::mutex mtx;
public :
    static Singleton* getInstance()
    {
        std::lock_guard<mutex> lock(mtx);

        if (!instance)
            instance = new Singleton();
        return instance;
    }

    void ShowMessage()
    {
        cout << "Testing Singleton Design Pattern" << endl;
    }

};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main()
{
    Singleton::getInstance()->ShowMessage();
    return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
