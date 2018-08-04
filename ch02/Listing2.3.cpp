
#include <iostream>
#include <thread>

//using RAII to wait for a thread to complete

class thread_guard
{
    std::thread &t;
public:

    explicit thread_guard(std::thread &t_) : t(t_){}

    ~thread_guard()
    {
        if(this->t.joinable())
            t.join();
    }

    //disable copy constructor by using =delete(c+11 feature)
    thread_guard(const thread_guard&) = delete;

    //disable copy assignment
    thread_guard & operator = (const thread_guard &) = delete;

};

void do_something(int i)
{
    std::cout << i << std::endl;
}

struct func
{
private:
    int a;
public:
    func(int & a_) : a(a_){};
    void operator()()
    {
        for(unsigned j = 0; j < 10; j++)
            do_something(a);
    }
};

void raise_exception()
{
    throw;
}

void f()
{
    int local_var = 10;
    func func_test(local_var);

    std::thread my_t(func_test);
    thread_guard g(my_t);

    //raise_exception();
    std::cout << "before exit" << std::endl;
}

int main()
{
    f();
}