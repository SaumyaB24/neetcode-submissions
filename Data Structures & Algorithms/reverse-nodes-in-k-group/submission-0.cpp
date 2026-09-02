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
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);//object
        dummy.next = head;
        ListNode* grpPrev = &dummy;//pointer
        while(true){
            ListNode* kth = grpPrev;
            for(int i = 0; i<k; i++){
                kth = kth->next;
                if(kth ==  nullptr)return dummy.next;
            }
            ListNode* grpStart = grpPrev->next;
            ListNode* grpNext = kth->next;
            kth->next = nullptr;
            ListNode* newHead = reverseLL(grpStart);
            grpPrev->next = newHead;
            grpStart->next = grpNext;
            grpPrev = grpStart;
        }
    }
};
