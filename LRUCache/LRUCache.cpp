#include <iostream>
#include <unordered_map>

class LRUCache 
{
private:
    std::unordered_map<int, int> lru;
    std::unordered_map<int, int> priority;
    int time = 0;
    int maxSize = 0;
public:
    LRUCache(int capacity) : maxSize(capacity)
    {
        lru.reserve(capacity);
        priority.reserve(capacity);
    }

    int get(int key) 
    {
        auto find = lru.find(key);

        if (lru.find(key) == lru.end())
        {
            return -1;
        }
        
        priority[key] = time++;
        return lru[key];
    }

    void put(int key, int value)
    {
        if (lru.size() >= maxSize && lru.find(key) == lru.end())
        {
            int minPriority = time;
            int minKey;
            for (const auto& l : priority)
            {
                if (l.second < minPriority)
                {
                    minPriority = l.second;
                    minKey = l.first;
                }
            }
            lru.erase(minKey);
            priority.erase(minKey);
        }

        lru[key] = value;
        priority[key] = time++;
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
