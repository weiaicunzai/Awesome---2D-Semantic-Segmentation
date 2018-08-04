
#include <iostream>
#include <thread>

class scoped_thread
{
    std::thread t;

  public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_))
    {
        if(!t.joinable())
            throw std::logic_error("no thread");
    }

    ~scoped_thread()
    {
        t.join();
    }

    //disable copy constructor
    scoped_thread(const scoped_thread &) = delete;

    //disable copy assignment
    scoped_thread& operator = (const scoped_thread &) = delete;
};

void count_numbers(unsigned i)
{
    std::cout << i <<std::endl;
}

struct func
{
    unsigned &i;

    //Error: cant bind a non-const reference to a const-object
    //it will break the const correctness
    //func(const int& i_) : i(i_){}

    //Error: A refference can't be reassigned, so it must be
    //initialized in the member initialization list
    //func(int& i_) 
    //{
    //    i = i_;
    //}

    func(unsigned & i_) : i(i_){}

    void operator() ()
    {
        for(unsigned j = 0; j < i; j++)
           count_numbers(j);
    }
};

void do_something_in_current_thread()
{}

void f()
{
    unsigned var = unsigned(10);
    scoped_thread t(std::thread(func(var)));

    std::cout << "exit function f" << std::endl;
}
int main()
{
    f();    
}

