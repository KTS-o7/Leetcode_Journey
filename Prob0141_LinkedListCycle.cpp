// My solution

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        if (head->next == NULL)
            return false;
        int flag = INT_MAX;
        ListNode *temp = head->next;

        while (temp->next != NULL)
        {
            if (temp->val == flag)
            {
                return true;
            }
            // cout<<temp->val<<endl;
            temp->val = flag;
            temp = temp->next;
        }

        return false;
    }
};

// Link to check : https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
// Optimum Solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       // std::ios::sync_with_stdio(false);
        if(head == NULL)
            return false;
        ListNode* first = head;
        ListNode* sec = head;
        while(first != NULL && first->next != NULL)
        {
            first=first->next->next;
            sec=sec->next;

            if(first == sec)
                return true;
        }
        return false;
    }
};

// Time complexity : O(n)
// Space complexity : O(1)
// Code explained :
// 1. We have two pointers
// 2. First pointer moves 2 steps at a time
// 3. Second pointer moves 1 step at a time
// 4. If there is a cycle, then both pointers will meet at some point
// 5. If there is no cycle, then first pointer will reach the end of the list
// 6. So, we can return false in that case
// 7. If there is a cycle, then we can return true
