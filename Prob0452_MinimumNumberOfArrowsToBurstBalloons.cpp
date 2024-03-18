class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cmp = points[0][1];
        int arrow = 1;
        
        for(int i = 1;i<points.size();i++)
        {
           
           
                if(cmp<points[i][0])
                    {
                        
                        arrow++;
                       cmp = points[i][1];
                    }
                else
                    cmp = min(cmp,points[i][1]);

        }

        return arrow;

        
    }
};

// Time complexity : O(nlogn)
// Space complexity : O(1)

// Logic Explained :
// 1. Sort the points based on the start of the points.
// 2. Initialize the cmp with the end of the first point and arrow with 1.
// 3. Iterate through the points and check if the cmp is less than the start of the next point, then increment the arrow and update the cmp with the end of the next point.
// If it is less it means that the arrow is not able to burst the balloon and we need to shoot another arrow.
// The updated the cmp with the end of the next point.
// 4. If the cmp is greater than the start of the next point, then update the cmp with the minimum of the cmp and the end of the next point.
// 5. Return the arrow.