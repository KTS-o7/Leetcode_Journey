class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        priority_queue<int>heap;

        for(const int it:happiness)
            heap.push(it);
        long long count = 0;
        long long answer = 0;
        while(k>0 && !heap.empty())
        {
            answer = ((heap.top()-count)>=0)?answer+heap.top()-count:answer+0;
            heap.pop();
            k--;
            count++;
        }

        return answer;

    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

// Logic Explained :
// 1. We will use a max heap to store the happiness values.
// 2. We will pop the top element from the heap and add it to the answer if the difference between the top element and the count is greater than 0.
// 3. We will decrement the count and the value of k.
// 4. We will return the answer.


// Alternate solution:
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long sum = 0;
        for(int i = 0; i < k; i++) {
            happiness[i] = max(0, happiness[i]-i);
            sum += happiness[i];
        }
        return sum;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(1)

// Logic Explained:
// 1. We will sort the happiness array in descending order.
// 2. We will iterate over the first k elements and add the happiness value to the answer if the difference between the happiness value and the index is greater than 0.
// 3. We will return the answer.
