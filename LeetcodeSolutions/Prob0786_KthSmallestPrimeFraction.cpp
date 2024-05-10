// Initial solution plan
// This was not that efficient as we were storing all the pairs in the heap and then popping the k-1 elements from the heap.

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        std::ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        auto comparePair = [](const pair<int,int>& a,const pair<int,int>& b)
        {
            return a.first*b.second > b.first*a.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(comparePair)>minheap;

        for(int i = 0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
                {
                    minheap.push(make_pair(arr[i],arr[j]));
                }
        }

        vector<int>answer(2,0);
        while(k>1 && !minheap.empty())
        {
            k--;
            minheap.pop(); 
        }
        answer[0] = minheap.top().first;
        answer[1] = minheap.top().second;
        return answer;
    }
};

// Time Complexity: O(n^2logn)
// Space Complexity: O(n^2)

// time complexity is O(n^2logn) because each insertion in the heap will take O(logn) time and there are n*(n-1)/2 elements in the heap.

// Logic Explained:
// 1. We will use a min heap to store the pairs of the array elements.
// 2. We will iterate over the array and store all the pairs in the heap.
// 3. We will pop the top element from the heap k-1 times.
// 4. We will return the top element of the heap as the answer.
