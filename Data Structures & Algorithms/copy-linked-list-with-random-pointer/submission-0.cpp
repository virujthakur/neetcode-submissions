/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> clone;
        Node* cur = head;
        while(cur!= nullptr){
            Node* newNode = new Node(cur->val);
            clone[cur] = newNode;
            cur = cur->next;
        }

        cur = head;
        Node* newHead= nullptr;

        while(cur!= nullptr){
            Node* node= clone[cur];
            if(newHead == nullptr) newHead = node;
            node->random = clone[cur->random];
            node->next= clone[cur->next];
            cur = cur->next;
        }
        return newHead;
    }
};
