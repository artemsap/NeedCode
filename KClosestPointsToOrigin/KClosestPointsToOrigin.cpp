#include <iostream>
#include <vector>
#include <queue>

class Solution 
{
private:
    static float distanceBetweenPointAndOrigin(const std::vector<int>& point)
    {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }

public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) 
    {
        auto less = [](const std::vector<int>& point1, const std::vector<int>& point2)
        {
            return distanceBetweenPointAndOrigin(point1) < distanceBetweenPointAndOrigin(point2);
        };

        std::make_heap(points.begin(), points.end(), less);

        while (points.size() != k)
        {
            std::pop_heap(points.begin(), points.end(), less);
            points.pop_back();
        }

        return points;
    }
};

int main()
{
    std::vector<std::vector<int>> points{ {0,2}, {2,0}, {2,2} };

    Solution sol;
    //auto res = sol.kClosest(points,2);

    std::vector<std::vector<int>> points2{ {3,3},  {-2,4} ,{5,-1} };
    auto res2 = sol.kClosest(points2, 2);

    std::cout << "Hello World!\n";
}
