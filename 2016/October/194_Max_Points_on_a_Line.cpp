/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int result = 0;
        int samePoint;
        for(int i = 0; i < points.size(); ++i) {
            samePoint = 1;
            unordered_map<double, int> slope;
            for(int j = i+1; j < points.size(); ++j) {
                if(points[i].x == points[j].x) {
                    if (points[i].y == points[j].y)
                        ++samePoint;
                    else
                        ++slope[INT_MAX];
                }
                else {
                    double k = double(points[i].y - points[j].y) /double(points[i].x - points[j].x);
                    slope[k]++; 
                }
            }
            int max = 0;
            for(auto t : slope)
                max = max > t.second?max:t.second;
            max += samePoint;
            result = result > max?result:max;
        }
        return result;
    }
};