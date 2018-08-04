

#include <iostream>
#include <thread>
#include <vector>


void print_num(int i)
{
    std::cout << "input number is " << i << std::endl;
}

void f()
{
    std::vector<std::thread> threads;
    for(int i = 0; i < 10; i++)
        threads.push_back(std::thread(print_num, i));
    

    //Error: use of deleted function ‘std::thread::thread(std::thread&)’
    //for(auto t : threads)
    for(std::vector<std::thread>::iterator iter = threads.begin(); iter != threads.end(); iter++)
    {
        (*iter).join();
    }

    std::cout << "exiting f function" << std::endl;
}
int main()
{
    f();
}