class Solution {
public:
    // Function to check if the occurrences of each element in arr are unique
    bool uniqueOccurrences(std::vector<int>& arr) {
        // Improve input/output operations performance
        std::ios::sync_with_stdio(false);
        // Untie cin and cout for performance improvement
        cin.tie(nullptr);

        // Map to store occurrences of each element
        std::unordered_map<int, int> occurrences;

        // Count occurrences of each element in arr
        for (int num : arr) {
            occurrences[num]++;
        }

        // Set to check for uniqueness of occurrences
        std::unordered_set<int> uniqueOccurrencesSet;

        // Iterate through the occurrences map
        for (auto entry : occurrences) {
            // Extract the occurrence count
            int temp = entry.second;

            // Check if the occurrence count is already in the set
            if (uniqueOccurrencesSet.find(temp) != uniqueOccurrencesSet.end()) {
                // If not unique, return false
                return false;
            } else {
                // If unique, insert the occurrence count into the set
                uniqueOccurrencesSet.insert(temp);
            }
        }

        // If the loop completes, all counts are unique
        return true;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

/* Code Explained :
ntuition
The intuition behind this solution is to utilize a hash map to count the occurrences of each element in the array. Subsequently, a set is employed to track the uniqueness of these occurrence counts. By iterating through the array and checking for unique occurrences, the function determines if all counts are indeed unique.

Approach
Utilize a hash map to count the occurrences of each element in the array.
Use a set to check for the uniqueness of these occurrence counts.
If any occurrence count is found more than once, return false. Otherwise, return true.

Algorithm
1. Create a hash map 'occurrences' to count the occurrences of each element in the array.
2. Iterate through the array, updating the occurrences in the hash map.
3. Create a set 'uniqueOccurrencesSet' to check for the uniqueness of these occurrence counts.
4. Iterate through the hash map entries:
    a. Extract the occurrence count.
    b. Check if the occurrence count is already in the set:
        - If yes, return false (not unique).
        - If no, insert the occurrence count into the set.
5. If the loop completes, return true (all counts are unique).*/