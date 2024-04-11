// Approach 1 : using loop

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        
    
            for(int i =0;i<tickets.size();i++)
            {
                if(i>k)
                {
                    time+= min(tickets[k]-1,tickets[i]);
                }
                else
                {
                    time+= min(tickets[k],tickets[i]);
                }
            }
            
    
        return time;
        
    }
};

// Time complexity : O(n)
// Space complexity : O(1)

// Logic explained :
// 1. Given a Queue of people waiting to buy tickets, and a counter k, which is initially set to 0.
// 2. They will be able to buy only two number of tickets - i) If they come after kth person, they can buy tickets equal to kth tickets - 1 or their tickets whichever is minimum.
// ii) If they come before kth person, they can buy tickets equal to kth tickets or their tickets whichever is minimum.
// 3. We need to find the time taken to buy tickets for kth person.
// 4. We can iterate through the queue and calculate the time taken to buy tickets for kth person.
// 5. Return the time taken to buy tickets for kth person.



