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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return head;
        int count = 0;
        ListNode* trav = head;
        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
        if(count < k)
            return head;
        if(k == 1)
            return head;
        
        int i = 2;
        ListNode* one = head;
        ListNode* two = head->next;
        ListNode* temp;
        while(i <= k)
        {
            temp = two->next;
            two->next = one;
            if(i == 2)
                one->next = NULL;
            one = two;
            two = temp;
            i++;
        }
        ListNode* nhead = one;
        if(two == NULL)
            return one;
        else
        {
            two = reverseKGroup(two, k);
            head->next = two;
        }
        return nhead;
    }
};
