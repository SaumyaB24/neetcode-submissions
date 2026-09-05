class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        this->key = key;
        this->val = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mp;

    Node* leastFrequent;
    Node* mostFrequent;

    LRUCache(int capacity) {
        this->capacity = capacity;

        mostFrequent = new Node(-1, -1);
        leastFrequent = new Node(-1, -1);

        mostFrequent->next = leastFrequent;
        leastFrequent->prev = mostFrequent;
    }

    // Add node just after head
    void addNode(Node* node) {
        node->next = mostFrequent->next;
        node->prev = mostFrequent;

        mostFrequent->next->prev = node;
        mostFrequent->next = node;
    }

    // Remove node from list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Mark as most recently used
        removeNode(node);
        addNode(node);

        return node->val;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->val = value;

            // Move to front
            removeNode(node);
            addNode(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);
        mp[key] = node;
        addNode(node);

        // Capacity exceeded
        if (mp.size() > capacity) {
            Node* lru = leastFrequent->prev;

            removeNode(lru);
            mp.erase(lru->key);

            delete lru;
        }
    }
};