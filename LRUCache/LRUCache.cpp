#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache 
{
private:
    std::list<int> priorities;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> lru;

    int maxSize = 0;

public:
    LRUCache(int capacity) : maxSize(capacity)
    {
    }

    int get(int key) 
    {
        if (lru.find(key) == lru.end())
        {
            return -1;
        }
        
        priorities.erase(lru[key].second);
        priorities.push_back(key);

        return lru[key].first;
    }

    void put(int key, int value)
    {
        if (lru.find(key) != lru.end())
        {
            priorities.erase(lru[key].second);
        }
        else if (lru.size() >= maxSize)
        {
            lru.erase(priorities.front());
            priorities.erase(priorities.begin());
        }

        priorities.push_back(key);
        lru[key] = std::make_pair(value, --priorities.end());
    }
};


int main()
{
    LRUCache lRUCache(2);
    std::cout << lRUCache.get(2) << std::endl;     
    lRUCache.put(2, 6); 
    std::cout << lRUCache.get(1) << std::endl;      
    lRUCache.put(1, 5);  
    lRUCache.put(1, 2);  
    std::cout << lRUCache.get(1) << std::endl;    
    std::cout << lRUCache.get(2) << std::endl;     

    std::cout << "Hello World!\n";
}
