

#include <iostream>
#include <thread>
#include <vector>
#include <numeric>  //std::accumulate
#include <algorithm> //std::for_each

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator() (Iterator first, Iterator second, T& result)
    {
        result = std::accumulate(first, second, result);
    }
};

template<typename Iterator, typename T>
T para_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = std::distance(first, last);

    if(!length)
        return init;
    
    unsigned long const min_per_thread = 25;

    unsigned long const max_threads = 
        (length + min_per_thread - 1) / min_per_thread;
    
    unsigned long const hardware_thread = 
        std::thread::hardware_concurrency();
    
    unsigned long const num_threads = 
        std::min(hardware_thread != 0 ? hardware_thread : 2, max_threads);
    
    //final block size
    unsigned long const block_size = length / num_threads;

    std::cout << "how many threads: " << std::endl;
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);

    Iterator block_start = first;
    for(unsigned long i = 0; i < (num_threads - 1); i++)
    {
        Iterator block_end = block_start;

        //move block_end block_size steps after
        std::advance(block_end, block_size);
        threads[i] = std::thread(
            accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));

        std::cout << "thread id :" << threads[i].get_id() << std::endl;
        block_start = block_end;
    }

    std::cout << std::distance(block_start, last) << std::endl;
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    return std::accumulate(results.begin(), results.end(), init);
}

int main()
{

    //int a[] = {1, 2, 33, 43, 5435, 6, 6546456, 7675, 77, 8, 768, 68, 9899, 789789924,234};
    //std::vector<int>  nums(a, a+ sizeof(a) / sizeof(int));
    std::vector<int> nums;
    for(int i = 0; i < 100; i++)
    {
        nums.push_back(i);
    }

    //int sum = para_accumulate<std::vector<int>::iterator, int>(nums.begin(), nums.end(), 0);
    //type can be ignored(only for template functions)
    int sum = para_accumulate(nums.begin(), nums.end(), 0);
    std::cout << sum << std::endl;


}