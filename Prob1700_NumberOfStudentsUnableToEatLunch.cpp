class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::ios::sync_with_stdio(false);
        queue<int>q;
        for(int it:students)
        {
            q.push(it);
        }
        int count = 0, i = 0,front;
        while(!q.empty() && q.size()!=count)
        {
            if(q.front() == sandwiches[i])
            {
                count = 0;
                i++;
                q.pop();
            }
            else
            {
                front = q.front();
                q.pop();
                count++;
                q.push(front);
            }
        }
        return count;
        
    }
};

// Time complexity : O(n)
// Space complexity : O(n)
 
// Logic Explained:
// 1. We will use a queue to store the students.
// 2. We will iterate over the queue until the queue is empty or the count of students is equal to the size of the queue.
// 3. If the front of the queue is equal to the sandwich at index i, then we will pop the front of the queue and increment the index i.
// 4. If the front of the queue is not equal to the sandwich at index i, then we will pop the front of the queue and push it to the back of the queue.
// 5. We will keep a count of the number of students who are not able to eat the sandwich.
// 6. Finally, we will return the count of students who are not able to eat the sandwich. 