class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n = heights.size();
        priority_queue<int> pq;
        for(int i=0;i<n-1;i++)
        {
            int diff = heights[i+1] - heights[i];            
            if(diff <= 0)
            {
                continue;
            }
            bricks -= diff;
            pq.push(diff);
            if(bricks<0)
            {
                if(ladders == 0)
                {
                    return i;
                }
                ladders--;
                bricks += pq.top();
                pq.pop();
            }
        }
        return n-1;
    }
};

// Time complexity : O(nlogn)
// Space complexity : O(n)

// Code explained :
// 1. We are using a priority queue to store the difference between the heights of the buildings.
// 2. We are iterating through the heights array and calculating the difference between the heights of the buildings.
// 3. If the difference is less than or equal to 0, we continue to the next iteration.
// 4. If the difference is greater than 0, we subtract the difference from the bricks.
// 5. This says that we are trying to make up the difference in height using bricks.
// 6. We are also pushing the difference into the priority queue.
// 7. This is to keep track of all the differences between the heights of the buildings.
// 8. If the bricks are not suffiecient to make up the difference, we check if we have ladders.
// 9. If we have ladders, we use the ladder to make up the difference and add the difference to the bricks.
// 10. The difference what we are adding is the greatest difference seen till that point so that we can use ladder then and save that much amount of bricks.
// 11. If we don't have ladders, we return the index of the building till which we have reached.
// 12. If we come out of the loop, we return the last index of the building. This is because we have reached the last building and we have used all the bricks and ladders. So, we can't go any further.