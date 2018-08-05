
#include <exception>
#include <memory>


//thread safe version
struct empty_stack : std::exception
{
    const char *what() const throw();
};

template <typename T>
class ThreadSafeStack
{
    public:
    ThreadSafeStack();

    //delete copy assignment
    ThreadSafeStack & operator = (const ThreadSafeStack &) = delete;

    void push(T new_value);
    std::shared_ptr<T> pop();
    void pop(T& pop);
    bool empty() const;
};

int main()
{

}