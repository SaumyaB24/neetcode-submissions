class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;

            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* head1 = lists[i];
                ListNode* head2 = (i+1)<lists.size()?lists[i + 1]:nullptr;

                mergedLists.push_back(mergeLists(head1, head2));
            }

            lists = mergedLists;
        }

        return lists[0];
    }

    ListNode* mergeLists(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }

            temp = temp->next;
        }

        if (head1 != nullptr)
            temp->next = head1;

        if (head2 != nullptr)
            temp->next = head2;

        return dummy.next;
    }
};