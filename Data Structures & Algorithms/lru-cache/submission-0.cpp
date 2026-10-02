class Node{
    public:
        Node* next;
        Node* prev;
        int val;
        int key;
};
class DLL{
    public:
    Node* head = new Node();
    Node* tail = new Node();
    DLL(){
        head->next= tail;
        tail->prev = head;
    }

    void insert(Node* node){
        node->prev= tail->prev;
        tail->prev->next= node;
        tail-> prev = node;
        node->next = tail;
    }

    Node* del(Node* node){
        node->prev->next= node->next;
        node->next->prev= node->prev;
        return node;
    }
};

class LRUCache {
public:
    
    unordered_map<int, Node*> keyToNode;
    DLL d;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(keyToNode.count(key) == 0) return -1;
        Node* node = keyToNode[key];
        Node* delNode = d.del(node);
        d.insert(delNode);
        return delNode->val;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1)
        {
            keyToNode[key]->val = value;
            return;
        }

        Node* newNode = new Node();
        newNode->key = key;
        newNode->val = value;
        if(keyToNode.size() == capacity){
            Node* delNode= d.del(d.head->next);
            keyToNode.erase(delNode->key);
            delete delNode;
        }
        d.insert(newNode);
        keyToNode[key] = newNode;
    }
};
