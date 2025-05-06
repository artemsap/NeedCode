#include <iostream>
#include <unordered_map>

class TimeMap 
{
public:
    TimeMap() 
    {

    }

    void set(std::string key, std::string value, int timestamp)
    {
        time[key].emplace_back(std::make_pair(timestamp, value));
    }

    std::string get(std::string key, int timestamp)
    {
        if (time.find(key) == time.end())
            return "";

        const auto& vec = time[key];

        std::string res = "";
        int left = 0;
        int right = vec.size() - 1;

        while (left < right)
        {
            int m_index = (right + left + 1) / 2;

            if (vec[m_index].first <= timestamp)
            {
                res = vec[m_index].second;
                left = m_index;
            }
            else
            {
                right = m_index - 1;
            }
        }

        if (res == "" && vec[0].first <= timestamp)
        {
            res = vec[0].second;
        }

        return res;
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> time;
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
