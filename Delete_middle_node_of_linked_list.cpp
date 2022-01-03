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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        if(head->next == NULL)
            return NULL;
        int i = 0;
        while(temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        ListNode* temp2 = head;
        i = i/2;
        int j = 0;
        while(j<i-1)
        {
            temp2 = temp2->next;
            j++;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};
