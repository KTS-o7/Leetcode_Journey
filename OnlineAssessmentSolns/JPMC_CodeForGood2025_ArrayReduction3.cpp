#include <bits/stdc++.h>
#include <set>
#include <cmath>
using namespace std;

int findTotalCost(vector<int> nums) {
    multiset<int> elements(nums.begin(), nums.end());

    int totalCost = 0;
    while (elements.size() > 1) {
        auto minElement = *elements.begin();
        elements.erase(elements.begin());

        auto maxElement = *elements.rbegin();
        elements.erase(prev(elements.end()));

        int sum = minElement + maxElement;
        totalCost += ceil((double)(maxElement + minElement) / (maxElement - minElement + 1));
        elements.insert(sum);
    }

    return totalCost;
}

// Time complexity: O(nlogn)
// Space complexity: O(n)

// Logic Explained:
// 1. We need to reduce the array to a single element.
// 2. We can solve this problem by using a multiset.
// 3. We will insert all the elements of the array into the multiset.
// 4. We will keep removing the minimum and maximum elements from the multiset.
// 5. We will calculate the  cost of operation as  (max+min)/(max-min+1) and add it to the total cost.
// 6. We will insert the sum of the minimum and maximum elements back into the multiset.
// 7. We will repeat this process until the multiset has only one element left.
// 8. The total cost will be the sum of all the costs calculated in each step.
// 9. We will return the total cost as the answer.
