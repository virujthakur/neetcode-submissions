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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1st node -> last node
        // 1 .. n
        // n-2 th node;
        ListNode* dummy = new ListNode();
        dummy->next= head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while(fast->next && n>0){
            fast = fast->next;
            n-=1;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
    
        slow->next = slow->next->next;
        return dummy->next;
    }

};
