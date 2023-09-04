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

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;
    }
};
