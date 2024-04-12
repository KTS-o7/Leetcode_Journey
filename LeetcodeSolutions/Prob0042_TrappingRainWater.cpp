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


// Approach 3: Using stack
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;
        for(int i = 0; i < height.size(); i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if(st.empty()) {
                    break;
                }
                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                water += distance * boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

// Logic explained :
/*Initialization: A stack st is initialized to keep track of the indices of the bars. The variable water is initialized to 0 to keep track of the total trapped water.
Iteration Over Heights: The code iterates over each bar (represented by its height) in the height vector.
Stack Operations:
While the stack is not empty and the current bar's height is greater than the height of the bar at the top of the stack, the code performs the following operations:
It pops the top element from the stack, which represents the index of the bar that is currently being considered as a potential boundary for trapping water.
If the stack becomes empty after popping, it breaks out of the loop because there are no more bars to consider as boundaries.
It calculates the distance between the current bar and the bar at the top of the stack. This distance represents the width of the trapped water.
It calculates the bounded height, which is the minimum height between the current bar and the bar at the top of the stack, minus the height of the bar that was just popped. This represents the height of the trapped water.
It adds the product of the distance and the bounded height to the total trapped water.
After the loop, it pushes the current bar's index onto the stack. This is done to keep track of the bars that are yet to be considered as potential boundaries for trapping water.
Return Total Trapped Water: Finally, the function returns the total trapped water.
The logic behind this solution is based on the observation that the amount of water that can be trapped between two bars is determined by the height of the shorter bar and the distance between the two bars. By using a stack, the algorithm efficiently keeps track of the bars that are yet to be considered as potential boundaries for trapping water, ensuring that the trapped water is calculated correctly.*/