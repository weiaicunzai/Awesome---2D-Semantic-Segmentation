
#include <iostream>
#include <thread>
#include <string>

void first_func()
{
    std::cout << "first function" << std::endl;
}

void second_func()
{
    std::cout << "second function" << std::endl;
}

std::thread f1()
{
    void msg(std::string s);
    return std::thread(msg, std::string("1st func"));
}

std::thread f2()
{
    void msg(std::string s);
    std::thread t (msg, "2st func");
    return t; 
}

int main()
{
    std::cout << "fff" << std::endl;

    std::thread t1(first_func);
    std::cout << "t1 is joinable: before " << t1.joinable() << std::endl;
    t1.join();
    std::cout << "t1 is joinable: after " << t1.joinable() << std::endl;

    std::thread t2;

    std::cout << "t2 is joinable: before " << t2.joinable() << std::endl;
    t2 = std::move(t1); // still not joinable even after transfor the ownership
    std::cout << "t2 is joinable: after " << t2.joinable() << std::endl;

    t2 = std::thread(second_func);
    std::cout << "t2 is joinable: second function before " << t2.joinable() << std::endl;
    t2.join();
    std::cout << "t2 is joinable: second function after " << t2.joinable() << std::endl;

    t1 = f1();
    t2 = f2();

    t1.join();
    t2.join();
}

void msg(std::string s)
{
    std::cout << s << std::endl;
}