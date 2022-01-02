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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        ListNode* ptr2 = head;
        if(head == NULL)
            return NULL;
        bool flag = false;
        jmp:
        while(ptr->next != NULL && ptr->val == ptr->next->val)
        {
            ptr = ptr->next;
            flag = true;
        }
        // if(ptr->next == NULL)
        //     return NULL;
        if(flag == true)
        {
            flag = false;
            ptr = ptr->next;
            if(ptr == NULL)
                return NULL;
            goto jmp;
        }
        head = ptr;
        ptr2 = head;
        ptr = ptr->next;
        flag = false;
        while(ptr!=NULL)
        {
            if(ptr->next == NULL)
            {
                if(flag == true)
                {
                    ptr2->next = NULL;
                    return head;
                }
                else
                {
                    ptr2->next = ptr;
                    return head;                  
                }
            }
            else
            {
                if(ptr->val == ptr->next->val)
                {
                    flag = true;
                    ptr = ptr->next;
                }
                else
                {
                    if(flag == true)
                    {
                        ptr = ptr->next;
                        flag = false;
                    }
                    else
                    {
                        ptr2->next = ptr;
                        ptr = ptr->next;
                        ptr2 = ptr2->next;
                    }
                }
            }
        }
        
        
        return head;
    }
};
