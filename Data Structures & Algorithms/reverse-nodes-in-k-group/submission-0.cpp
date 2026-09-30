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
    vector<ListNode*> reverse(stack<ListNode*>& st){
        ListNode* curHead = st.top();
        ListNode* cur = st.top();
        ListNode* prev = nullptr;
        st.pop();

        while(!st.empty()){
            prev = st.top();
            cur->next = prev;
            st.pop();
            cur = prev;
        }
        ListNode* curTail = cur;
        return {curHead, curTail};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;

        ListNode* cur = head;
        ListNode* newHead = nullptr;
        ListNode* prevGroupTail = nullptr;
        while(cur!= nullptr){
            stack<ListNode*> st;
            while(cur!= nullptr && st.size() < k){
                st.push(cur);
                cur = cur->next;
            }
            
            if(st.size() == k){
                // cout<<cur->val<<endl;
                vector<ListNode*> ptrs = reverse(st);
                ListNode* groupHead = ptrs[0];
                ListNode* groupTail = ptrs[1];
                
                if(prevGroupTail != nullptr){
                    prevGroupTail->next = groupHead;
                }
                groupTail->next= cur;
                if(newHead == nullptr) newHead = groupHead;
                prevGroupTail = groupTail;
            }
            else{
                if(newHead == nullptr) newHead = head;
                break;
            }
        }
        return newHead;
    }
};
