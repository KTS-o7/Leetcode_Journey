class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        int xdist = abs(fx-sx);
        int ydist = abs(fy-sy);
        if(xdist==0 && ydist==0)
            return t!=1;
        return (xdist<=t && ydist <= t);
        
    }
};

// Time complexity: O(1)
// Space complexity: O(1)
// fast io code snippet is used to optimise input and output speed
// The above code snippet is a solution to find if a cell is reachable in a given time in an infinite grid.
// The solution is based on the fact that if a cell is reachable in a given time, then the distance between the source and the destination cell
// should be less than or equal to the given time.
// The distance between the source and the destination cell is the absolute difference between the x and y coordinates of the source and the destination cell.
// Also 1 second is the time required to traverse one cell.
// Hence, if the distance between the source and the destination cell is less than or equal to the given time, then the cell is reachable in the given time.
// If the start and finish cell is same its unreachable if time is only 1 second.