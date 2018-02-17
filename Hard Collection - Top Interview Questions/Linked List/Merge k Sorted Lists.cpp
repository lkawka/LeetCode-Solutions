/*
 Problem:
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int, int> PII;
        int N = lists.size();
        ListNode* head = NULL;
        ListNode* tail;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        
        for(int i = 0; i < N; i++) {
            if(lists[i]) {
                q.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        
        while(!q.empty()) {
            PII top = q.top();
            q.pop();
            
            if(lists[top.second]) {
                q.push({lists[top.second]->val, top.second});
                lists[top.second] = lists[top.second]->next;
            }
            if(!head) {
                head = new ListNode(top.first);
                tail = head;
            } else {
                tail->next = new ListNode(top.first);
                tail = tail->next;
            }
        }
        return head;
    }
};
