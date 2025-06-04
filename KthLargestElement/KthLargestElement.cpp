#include <iostream>
#include <vector>
#include <queue>

class KthLargest
{
private:
    std::priority_queue<int, std::deque<int>, std::greater<int>> priority_queue;
    int k_largest;

public:
    KthLargest(int k, std::vector<int>&nums) : k_largest(k), priority_queue(nums.begin(), nums.end())
    {
        while (priority_queue.size() > k_largest)
        {
            priority_queue.pop();
        }
    }

    int add(int val) 
    {
        priority_queue.push(val);

        while (priority_queue.size() > k_largest)
        {
            priority_queue.pop();
        }

        return priority_queue.top();
    }
};


int main()
{
    std::vector<int> nums = { 1, 2, 3, 3 };
    KthLargest kthLargest(3, nums);
    std::cout << kthLargest.add(3) << std::endl; // return 3
    std::cout << kthLargest.add(5) << std::endl; // return 3 
    std::cout << kthLargest.add(6) << std::endl; // return 3
    std::cout << kthLargest.add(7) << std::endl; // return 5
    std::cout << kthLargest.add(8) << std::endl; // return 6

}

