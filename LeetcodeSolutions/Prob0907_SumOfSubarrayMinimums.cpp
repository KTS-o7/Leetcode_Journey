// Better Solution :





// Brute Force Solution:
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        const int MOD = 1e9 + 7;
        long long sum = 0;
        int n = arr.size();
        

        for (int i = 0; i < n; i++) {
            // For each element, find the minimum element in all possible subsets
            int min_in_subset = arr[i];
            for (int j = i; j < n; j++) {
                min_in_subset = min(min_in_subset, arr[j]);
                sum+=min_in_subset;
            }
            sum%=MOD;
        }

        return static_cast<int>(sum);
    }
};

