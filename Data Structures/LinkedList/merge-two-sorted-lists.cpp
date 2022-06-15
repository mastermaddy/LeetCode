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
    ListNode* mergeKLists(vector<ListNode*> lists){
       priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        ListNode* head = nullptr, *tail = nullptr;
        for(auto list:lists){
            if(list!=nullptr){
                pq.push({list->val,list});
            }
        }
        if(!pq.empty()){
            pair<int, ListNode*> currSmallest = pq.top();
            pq.pop();
            head = new ListNode(currSmallest.first);
            tail = head;
            currSmallest.second = currSmallest.second->next;
            if(currSmallest.second!=nullptr){
                pq.push({currSmallest.second->val, currSmallest.second});
            }
        }
        while(!pq.empty()){
            pair<int, ListNode*> currSmallest = pq.top();
            pq.pop();
            tail->next = new ListNode(currSmallest.first);
            tail = tail->next;
            currSmallest.second = currSmallest.second->next;
            if(currSmallest.second!=nullptr){
                pq.push({currSmallest.second->val, currSmallest.second});
            }
        }
        return head; 
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<ListNode*> lists;
        lists.push_back(l1);
        lists.push_back(l2);
        return mergeKLists(lists);
    }
};
