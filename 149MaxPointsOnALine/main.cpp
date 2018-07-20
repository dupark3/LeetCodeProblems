#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a point.
struct Point {
   int x;
   int y;
   Point() : x(0), y(0) {}
   Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        size_t points_size = points.size();
        if (points_size <= 2){
            return points_size;
        }

        int max_points = 0;

        for (int i = 0; i != points_size; ++i){
            unordered_map<long double, int> slopes;
            int overlap = 0;
            for (int j = i + 1; j != points_size; ++j){
                if (points[i].x == points[j].x && points[i].y == points[j].y){
                    ++overlap;
                    ++slopes[INT_MIN];
                } else {
                    long double slope = INT_MAX;
                    if ((points[i].x - points[j].x) != 0){
                        slope = (long double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                    }
                    ++slopes[slope];
                }
            }
            auto iter = slopes.begin();
            while (iter != slopes.end()){
                // cout << "i: " << i << " slope: " << iter->first << " points: " << iter->second << endl;
                if (iter->first != INT_MIN){
                    max_points = max(max_points, iter->second + 1 + overlap);
                } else { 
                    max_points = max(max_points, iter->second + 1);
                }
                
                ++iter;
            }
        }

        return max_points;
    }
};

int main() {
    Solution solution;
    vector<Point> points = 
        { Point(1,1), Point(3,2), Point(5,3), Point(4,1), Point(2,3), Point(1,4) };
    vector<Point> points2 = { Point(0,0), Point(94911151,94911150), Point(94911152,94911151)};

    cout << solution.maxPoints(points2) << endl;

    return 0;
}