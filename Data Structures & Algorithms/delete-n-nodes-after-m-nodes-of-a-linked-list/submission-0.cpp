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
    ListNode* deleteNodes(ListNode* head, int m, int n) 
    {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(head != nullptr)
        {
            for(int i = 0; i < m; i++)
            {
                if(head == nullptr) break;

                curr->next = head;
                curr = curr->next;
                head = head->next;
            }

            for(int i = 0; i < n; i++)
            {
                if(head == nullptr) break;

                head = head->next;
            }
        }  

        curr->next = nullptr;
        return dummy.next;  
    }
};
