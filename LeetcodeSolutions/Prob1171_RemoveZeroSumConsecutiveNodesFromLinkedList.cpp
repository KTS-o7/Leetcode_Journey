/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        
        ListNode* dummy = new ListNode(0,head);
        ListNode* temp = dummy;
        ListNode* start=NULL;
        int sum=0,psum=0;
        while(temp!=NULL)
        {
            sum+= temp->val;
            if(mp.find(sum)==mp.end())
            {  // cout<<sum<<endl;
                mp[sum]=temp;
            } 
            else
            {  // cout<<sum<<endl;
                start = mp[sum]->next;
                psum = sum + start->val;
                while(psum != sum)
                {
                    mp.erase(psum);
                    start = start->next;
                    psum += start->val;
                }
                mp[sum]->next = start->next;
            }
            temp=temp->next;
            
        }
        return dummy->next;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Code explained :
// 1. We will create a dummy node and point it to the head of the linked list.
// 2. We will create a map to store the sum and the node at which the sum was found.
// 3. We will iterate through the linked list and keep adding the sum to the map.
// 4. If the sum is already present in the map, we will remove the nodes from the map and the linked list.
// 5. Return the next of the dummy node.
// 6. Done.
// Dry run for the input [1,3,2,-3,-2,5,5,-5,1]
// map is of from {sum:node}
// 1. sum = 0, psum = 0, start = NULL, temp = 0 mp = {}
// 2. sum = 1, psum = 1, start = NULL, temp = 1 mp = {0:0}
// 3. sum = 4, psum = 4, start = NULL, temp = 3 mp = {0:0,1:1,4:3}
// 4. sum = 6, psum = 6, start = NULL, temp = 2 mp = {0:0,1:1,4:3,6:2}
// 5. sum = 3, psum = 3, start = NULL, temp = -3 mp = {0:0,1:1,4:3,6:2,3:-3}
// 6. sum = 1, psum = 1, start = NULL, temp = -2 mp = {0:0,1:1,4:3,6:2,3:-3,1:-2}
// Now we have found the sum 1 again, so we will remove the nodes from the map and the linked list.
// 7. sum = 6, psum = 6, start = 5, temp = 5 mp = {0:0,1:1,6:5}
// 8. sum = 11, psum = 11, start = 5, temp = 5 mp = {0:0,1:1,6:5,11:5}
// 9. sum = 6, psum = 6, start = 5, temp = -5 mp = {0:0,1:1,6:5,11:5,6:-5}
// Now we have found the sum 6 again, so we will remove the nodes from the map and the linked list.
// 10. sum = 7, psum = 7, start = 5, temp = 1 mp = {0:0,1:1,6:5,7:1}
// Reached end of Linked list, return the next of the dummy node.

