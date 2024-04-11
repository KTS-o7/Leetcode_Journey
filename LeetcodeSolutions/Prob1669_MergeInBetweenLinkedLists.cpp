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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ListNode* start = list1;
        ListNode* temp; 
        for(int i = 1; i < a; i++)
            start = start->next;

        ListNode* end = start->next;
        for(int i = a; i <= b; i++) {
            temp = end;
            end = end->next;
            delete temp;
        }

        start->next = list2;
        while(list2->next != nullptr)
            list2 = list2->next;

        list2->next = end;
        return list1;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)

// Code logic explained :
// 1. Traverse the list1 till the node a-1 and store the address of the node in start.
// 2. Traverse the list1 till the node b and store the address of the node in end.
// 3. Delete the nodes between a and b.
// 4. Connect the start node to list2.
// 5. Traverse the list2 till the end and connect the end node to list2.
// 6. Return the list1.