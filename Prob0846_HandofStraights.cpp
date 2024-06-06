class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    if (hand.size() % groupSize != 0) 
        return false;
    

    map<int, int> freqCount;

    for (const int& card : hand) 
        freqCount[card]++;
    

    for (auto it = freqCount.begin(); it != freqCount.end(); ++it) 
    {
        if (it->second > 0)
        {
            int count = it->second;
            for (int i = 0; i < groupSize; ++i) 
            {
                if (freqCount[it->first + i] < count) 
                    return false;
                
                freqCount[it->first + i] -= count;
            }
        }
    }

    return true;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

// Logic explained :
// 1. If the number of elements in the hand is not divisible by groupSize, then return false as groups cannot be formed.
// 2. Create a map to store the frequency of each number in the hand.
// 3. Iterate through the map and for each number, check if the frequency of number is greater than 0.
// 4. If yes, then iterate through the groupSize and check if the frequency of the number + i is less than the count.
// 5. This will tell if we can form a group of size = groupSize and elements are consecutive.
// 6. If not, return false.
// 7. If all the groups are formed, return true.