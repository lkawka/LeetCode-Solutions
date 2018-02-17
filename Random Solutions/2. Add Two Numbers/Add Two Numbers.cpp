/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0), *pointer = &result;
        int leftOver = 0;
        while(l1 || l2 || leftOver)
        {
            int sum = leftOver;
            if(l1)  {sum += l1->val; l1 = l1->next;}
            if(l2)  {sum += l2->val; l2 = l2->next;}
            pointer = (pointer->next = new ListNode (sum%10));
            leftOver=sum/10;
        }
        return result.next;
        
    }
};