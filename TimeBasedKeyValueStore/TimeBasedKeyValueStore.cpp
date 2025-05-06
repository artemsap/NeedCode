#include <iostream>
#include <map>
#include <unordered_map>

class TimeMap 
{
public:
    TimeMap() 
    {

    }

    void set(std::string key, std::string value, int timestamp)
    {
        time[key][timestamp] = value;
    }

    std::string get(std::string key, int timestamp)
    {
        auto it = time[key].upper_bound(timestamp);

        if (it == time[key].begin())
            return "";
        else
            return std::prev(it)->second;
    }

private:
    std::unordered_map<std::string, std::map<int, std::string>> time;
};


int main()
{
    TimeMap timeMap;
    timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
    std::cout << timeMap.get("alice", 1) << std::endl;           // return "happy"
    std::cout << timeMap.get("alice", 2) << std::endl;         // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
    timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
    std::cout << timeMap.get("alice", 3) << std::endl;          // return "sad"
    std::cout << timeMap.get("alice", 2) << std::endl;
    std::cout << timeMap.get("alice", 0) << std::endl;
    std::cout << timeMap.get("alice", 1) << std::endl;           // return "happy"
}
