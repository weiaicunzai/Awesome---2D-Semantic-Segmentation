
#include <iostream>
#include <thread>

void test_var(unsigned &i)
{
    i++;
}

struct func
{
    unsigned i;
    func(unsigned &i_) : i(i_){}
    void operator()()
    {
        for (unsigned j = 0; j < 13; j++)
        {
            test_var(i);
            std::cout << j << std::endl;
        }
    }
};

void do_something()
{

}

void run()
{
    unsigned a = 0;
    func test_local(a);

    std::thread my_t(test_local);

    //To avoid your application being terminated when 
    //an exception is thrown
    try
    {
        do_something();
    }
    catch(...)
    {
        //we dont want thread to be terminaled if an
        //expcetion was raised
        my_t.join();
    }
    my_t.join();
}


int main()
{
    run();
    std::cout << "hello" << std::endl;

}