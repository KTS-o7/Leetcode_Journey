
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> rectangles;
        vector<int> current_rectangle = {points[0][0], points[0][1]};
        
        for (const auto& point : points) {
            if (point[0] - current_rectangle[0] <= w) {
               
                current_rectangle[1] = max(current_rectangle[1], point[1]);
            } else {
                
                rectangles.push_back(current_rectangle);
                current_rectangle = {point[0], point[1]};
            }
        }
        
        
        rectangles.push_back(current_rectangle);
        
        return rectangles.size();
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// Logic Explained :
// 1. Sort the points based on x coordinate.
// 2. Iterate through the points and keep track of the current rectangle.
// 3. If the x coordinate of the current point is within w distance from the x coordinate of the current rectangle, update the y coordinate of the current rectangle.
// 4. If the x coordinate of the current point is not within w distance from the x coordinate of the current rectangle, add the current rectangle to the list of rectangles and update the current rectangle.
// 5. Finally, add the current rectangle to the list of rectangles.
// 6. Return the number of rectangles.