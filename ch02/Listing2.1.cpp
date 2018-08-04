
#include <iostream>
#include <thread>


void print_num(unsigned &i)
{
    std::cout << i++ << std::endl;
}

struct func
{
    unsigned &i;
    func(unsigned &i_) : i(i_){}
    void operator()()
    {
        for(unsigned j = 0; j < 13; j++)
        {
            print_num(i);
        }
    }
};

void oops()
{
    unsigned local_var = 0;
    func test_func(local_var);

    std::thread my_thread(test_func);

    //test_func instance will not be destoried 
    //before oops funcions exits
    my_thread.join();

    //if i use my_thread.detached(), local_var might
    //be destoried before my_thread stops
    //so func.i will point to an address
    //which has been destoried, this is not
    //safe, in this case, we better use a copy instead
    //of reference, or just use my_tread.join()
}

int main()
{
    oops();
}
