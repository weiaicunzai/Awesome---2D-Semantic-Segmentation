
#include <mutex>
#include <string>
#include <iostream>

class Data
{
    int i;
    std::string s;
public:
    void hello()
    {
        std::cout << "I got the data" << std::endl;
    }
};

class Data_Wrapper
{
    Data d;
    std::mutex m;
public:
    template<typename func>
    void process_data(func f)
    {
        std::lock_guard<std::mutex> l(this->m);
        f(this->d);
    }

    void hello()
    {
        std::cout << "hello, I get the data" << std::endl;
    }
};

Data* store_data;


void steal_data(::Data &d)
{
    Data my_d = d;

    //this will make d not under mutext protection
    store_data = &my_d;
    std::cout << "the data is no longer under mutex protection" << std::endl;
}

int main()
{
    Data_Wrapper d;
    d.process_data(steal_data);
    store_data->hello();
}
