
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
      
        int size = points.size();
        int max=0;
        vector<int>xVals;
        for(int i=0;i<size;i++)
        {
            xVals.push_back(points[i][0]);
        }
        sort(xVals.begin(),xVals.end());
        for(int i=0;i<size-1;i++)
            if(max<xVals[i+1]-xVals[i])
                max =xVals[i+1]-xVals[i];


        return max;
    }
};