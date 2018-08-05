
#include <deque>

//not a thread safe Stack class

template <typename T, typename Container = std::deque<T>>
class Stack
{
  public:
    explicit Stack(const Container&);
    explicit Stack(const Container&& = Container());
    template <typename Alloc> explicit Stack(const Alloc&);
    template <class Alloc> Stack(const Container&, const Alloc&);
    template <class Alloc> Stack(Container&&, const Alloc&);
    template <class Alloc> Stack(Stack&&, const Alloc&);


    bool empty() const;
    std::size_t size() const;

    T const &top() const;
    void pop();
};

int main()
{
    //Stack<int> stack;

    //those 2 operations in multithreads
    //could cause race condition
    //stack.top();
    //stack.pop();
}