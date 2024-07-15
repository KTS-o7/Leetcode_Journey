class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int len;
    KthLargest(int k, vector<int> nums) {
        len=k;
        for(auto val:nums) {
            pq.push(val);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>len) pq.pop();
        return pq.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


// Time Complexity: O(nlogk) for constructor and O(logk) for add
// Space Complexity: O(k) for constructor and O(1) for add

// Explanation:
/*
1. We use a max heap to store the elements. This will help us to return the kth largest element in O(1) time.
2. We maintain the size of the heap to be k. So, if the size of the heap exceeds k, we pop the top element.
3. In the constructor, we push the elements into the heap and maintain the size of the heap to be k.
4. In the add function, we push the element into the heap and maintain the size of the heap to be k.
5. We return the top element of the heap which is the kth largest element.
*/