// Approach 1
// using set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>ans;

        vector<int>A;
       for(int it1:nums1)
            for(int it2:nums2)
                if(it1 == it2)
                    ans.insert(it1);

        for(int it:ans)
            A.push_back(it);
        return A;
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n+m)
// Code explained :
// 1. Create a set to store the unique elements of the intersection of the two arrays.
// 2. Create a vector to store the elements of the set.
// 3. Iterate through the first array and the second array and check if the elements are equal.
// 4. If the elements are equal, insert the element into the set.
// 5. Iterate through the set and insert the elements into the vector.
// 6. Return the vector.


// Approach 2
// Using two pointers
class Solution {
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>ans;
        vector<int>A;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                ans.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        for(int it:ans)
            A.push_back(it);
        return A;
    }
};

// Time Complexity: O(nlogn + mlogm)
// Space Complexity: O(n+m)
// Code explained :
// 1. Create a set to store the unique elements of the intersection of the two arrays.
// 2. Create a vector to store the elements of the set.
// 3. Sort the two arrays.
// 4. Create two pointers i and j and iterate through the two arrays.
// 5. If the elements are equal, insert the element into the set and increment the pointers.
// 6. If the element in the first array is less than the element in the second array, increment the first pointer.
// 7. If the element in the first array is greater than the element in the second array, increment the second pointer.
// 8. Iterate through the set and insert the elements into the vector.
// 9. Return the vector.
