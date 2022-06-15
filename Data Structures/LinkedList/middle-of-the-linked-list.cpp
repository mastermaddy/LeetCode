ListNode* getMiddleOfList(ListNode* head, ListNode* tail = nullptr){
    ListNode* fast = head, *slow = head;
    while(fast!=tail && fast->next!=tail){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
