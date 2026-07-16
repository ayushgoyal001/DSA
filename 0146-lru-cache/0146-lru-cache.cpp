class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int _key, int _value) {
            key = _key;
            value = _value;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }

    void addnode(Node* newnode) {
        Node* temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];

        deletenode(node);
        addnode(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mpp.find(key) != mpp.end()) {
            Node* existingnode = mpp[key];
            existingnode->value = value;

            deletenode(existingnode);
            addnode(existingnode);
            return;
        }

        // Cache full
        if (mpp.size() == cap) {
            Node* lru = tail->prev;

            mpp.erase(lru->key);
            deletenode(lru);
            delete lru;
        }

        Node* newnode = new Node(key, value);
        addnode(newnode);
        mpp[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */