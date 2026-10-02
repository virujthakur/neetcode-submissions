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
    ListNode* reverse(ListNode* cur){
        if(cur == nullptr) return nullptr;
        
        if(cur->next == nullptr){
            return cur;
        }
        ListNode* head = reverse(cur->next);
        cur->next->next = cur;
        cur->next= nullptr;
        return head;
    }
    void merge(ListNode* l1, ListNode* l2){
    
        while(l2!= nullptr){
            ListNode* nxtL1 = l1->next;
            ListNode* nxtL2 = l2->next;
            l1->next = l2;
            l2->next= nxtL1;
            l1 = nxtL1;
            l2 = nxtL2;
        }
    }
    void reorderList(ListNode* head) {
        // find mid
        // 1   2 3 4 5 
        // s,f
        //   s   f
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = slow->next;
        cout<<slow->val<<endl;
        slow->next= nullptr;
        
        ListNode* revl2 = reverse(l2);
        // while(revl2!= nullptr){
        //     cout<<revl2->val<<endl;
        //     revl2 = revl2->next;
        // }
        merge(head, revl2);
        // return head;
    }
};
