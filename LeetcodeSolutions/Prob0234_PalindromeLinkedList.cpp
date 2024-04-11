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
    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        vector<int>pali;
        while(first!=NULL)
            {
                pali.push_back(first->val);
                first=first->next;
            }
        
        int l =0 , r = pali.size()-1;
        while(l<r)
        {
            if(pali[l]!=pali[r])
                return false;
            l++;
            r--;
        }
        return true;
            


    }
};

// Time complexity : O(n)
// Space complexity : O(n)

// Logic explained :
// 1. We will iterate through the linked list and store the values of the nodes in a vector.    
// 2. We will then iterate through the vector from the start and end and compare the values.
// 3. If the values are not palindromic we will return false.
// 4. If we reach the end of the vector and all the values are palindromic we will return true.

// Approach 2

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // Find the end of first half and reverse second half.
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // Check whether or not there's a palindrome.
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) result = false;
            p1 = p1->next;
            p2 = p2->next;
        }        

        // Restore the list and return the result.
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

private:
    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

// Time complexity : O(n)
// Space complexity : O(1)

// Logic explained :
// 1. We will find the end of the first half of the linked list.
// 2. We will reverse the second half of the linked list.
// 3. We will compare the values of the first half and the reversed second half.
// 4. If the values are not palindromic we will return false.
// 5. If the values are palindromic we will return true.