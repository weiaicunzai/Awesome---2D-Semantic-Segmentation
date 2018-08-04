
#include <iostream>
#include <thread>

void hello()
{
    std::cout << "你好，世界" << std::endl;
}


int main()
{

    std::cout << std::thread::hardware_concurrency() << std::endl;
    //std::terminate();
    //new thread named t, and t's inital function is hello
    std::thread t(hello);

    //if we dont detach or join a thread, when the thread is 
    //destoried, it calls std::terminate() function
    t.detach();

    //main thread waits the new thread t to execute
    //t.join();

}


