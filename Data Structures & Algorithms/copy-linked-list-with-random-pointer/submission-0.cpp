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
        map<Node*, Node*> mpp;
        Node* temp = head;
        mpp[nullptr] = nullptr;
        while(temp != NULL){
            mpp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            mpp[temp]->next = mpp[temp->next];
            mpp[temp]->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }
};
