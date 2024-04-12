// Approach: Using two arrays to track height
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>leftMaxHeight(height.size()), rightMaxHeight(height.size());
        int size = height.size(), water = 0;
        leftMaxHeight[0] = height[0];
        rightMaxHeight[size-1] = height[size-1];
        for(int i =1;i<size;i++)
        {
            leftMaxHeight[i] = max(leftMaxHeight[i-1],height[i]);
        }
        for(int i = size-2;i>=0;i--)
        {
            rightMaxHeight[i] = max(rightMaxHeight[i+1],height[i]);
        }
        /*for(int i = 0;i<size;i++)
        {
            cout<<leftMaxHeight[i]<<" "<<rightMaxHeight[i]<<endl;
        }*/

        for(int i = 0;i<size;i++)
        {
            water+= min(leftMaxHeight[i],rightMaxHeight[i])-height[i];
        }
        return water;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

// Logic explained :
// 1. We are using two arrays to track the maximum height of the building on the left and right side of the current building.
// 2. We are then calculating the water that can be trapped on the current building by taking the minimum of the maximum height on the left and right side of the building and subtracting the height of the building.
// 3. First we find the maximum height of the building on the left side of the current building and store it in the leftMaxHeight array.
// 4. Then we find the maximum height of the building on the right side of the current building and store it in the rightMaxHeight array.
// 5. We then iterate through the height array and calculate the water that can be trapped on the current building by taking the minimum of the maximum height on the left and right side of the building and subtracting the height of the building.
// 6. Water can only be upto height of the minimum of the maximum height on the left and right side of the building.
// 7. We have to subtract the height of the building at that spot to check if the water level is hindered by the building.
// 8. We add the water trapped on each building to the total water trapped and return the total water trapped.


// Approach 2: Using two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, leftMax = 0, rightMax = 0, water = 0;
        while(left < right) {
            if(height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)

// Logic explained :
// 1. We are using two pointers to track the left and right side of the building.
// 2. We are using two variables leftMax and rightMax to track the maximum height of the building on the left and right side of the current building.
// 3. We are then calculating the water that can be trapped on the current building by taking the minimum of the maximum height on the left and right side of the building and subtracting the height of the building.
// 4. When the height of the building on the left side is less than the height of the building on the right side, we calculate the water that can be trapped on the left building and add it to the total water trapped.
// 5. We then increment the left pointer.
// 6. When the height of the building on the right side is less than the height of the building on the left side, we calculate the water that can be trapped on the right building and add it to the total water trapped.
// 7. We then decrement the right pointer.
// 8. We continue this process until the left pointer is less than the right pointer.
// 9. We add the water trapped on each building to the total water trapped and return the total water trapped.
