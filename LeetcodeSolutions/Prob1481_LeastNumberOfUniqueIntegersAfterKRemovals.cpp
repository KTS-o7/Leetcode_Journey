class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int,int>map;
        for(auto i:arr)
            map[i]++;
        int uniq = map.size();
        vector<int>freq(100000,0);
        for(auto i:map)
            freq[i.second]++;

        for(int i= 1;i<100000;i++)
            {
                if(freq[i]==0)
                    continue;
                int left =k/i;
                if(left==0)
                    break;
                else
                    {
                        left = min(left,freq[i]);
                        uniq -= left;
                        k -= left*i;
                    }
            }
            return uniq;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// Code explained :
// 1. We will use a map to store the frequency of each element in the array.
// 2. We will use a vector to store the frequency of each frequency of the elements in the array.
// 3. We will iterate through the vector and check if the frequency of the element is greater than 0.
// 4. If yes, we will calculate the number of elements that can be removed from the array and update the value of k.
// 5. We will return the number of unique elements left in the array.

// Logic behind the algorithm
// In the frequency vector, we are storing the frequency of the frequency of the elements in the array.
// For example, if the frequency of an element is 3, then we will store the frequency of that element at the 3rd index of the frequency vector.
// This will tell us how many elements have same frequency in the array.
// We will iterate through the frequency vector and check if the frequency of the element is greater than 0.
// If yes it means we might remove some of them.
// This is calculated by dividing k by the frequency of the element.
// This will tell us how many elements we can remove from the array.
// That means left is the number of elements that can be removed from the array.
// We will update the value of k by subtracting left * frequency of the element.(this basically says we reomved left number of elements from the array)
// We will return the number of unique elements left in the array.
