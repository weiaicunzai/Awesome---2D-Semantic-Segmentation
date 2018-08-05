
#include <list>
#include <mutex>
#include <thread>
#include <algorithm>
#include <iostream>
#include <fstream>

std::list<int> nums;
std::mutex m;

void add_to_list(int value)
{
    std::lock_guard<std::mutex> guard(m);

    //cout is also under protection of mutex(only inside this function)
    std::cout << "number " << value << " added" << std::endl;
    nums.push_back(value);
}

void list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(m);
    if(std::find(nums.begin(), nums.end(), value_to_find) == nums.end())
        std::cout << "dont contain " << value_to_find << std::endl;
    else
        std::cout << "contains " << value_to_find << std::endl;
}

int main()
{
    //add_to_list(42);
    for(int i = 0; i < 10; i++)
    {
        std::thread t(add_to_list, i);
        ////t.join();
        t.detach();
        t = std::thread(list_contains, i);
        t.detach();
    }

}