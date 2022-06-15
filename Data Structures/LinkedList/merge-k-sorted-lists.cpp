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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        ListNode *head = nullptr, *tail = nullptr;
        for(auto list:lists){
            if(list!=nullptr){
                pq.push({list->val, list});
            }
        }
        if(!pq.empty()){
            head = pq.top().second;
            pq.pop();
            tail = head;
            if(head->next){
                pq.push({head->next->val, head->next});
            }
        }
        while(!pq.empty()){
            ListNode* currTop = pq.top().second;
            pq.pop();
            tail->next = currTop;
            tail = currTop;
            if(currTop->next){
                pq.push({currTop->next->val, currTop->next});
            }
        }
        return head;
    }
};
