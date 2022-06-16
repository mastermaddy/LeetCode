class node{
public:
    int val;
    node* next;
    node(int x){
        val = x;
        next = nullptr;
    }
};
class MinStack {
private:
    node* head;
	map<int, int> mp;
public:
    MinStack() {
        head = nullptr;
    }

    void push(int val) {
        node* temp = new node(val);
        temp -> next = head;
        head = temp;
        if(mp.find(val)==mp.end()){
            mp[val];
        }
        mp[val]++;
    }

    void pop() {
        if(head){
            node* temp = head;
            head = head->next;
            if(mp.find(temp->val)!=mp.end()){
                mp[temp->val]--;
                if(mp[temp->val]==0) mp.erase(temp->val);
            }
            delete temp;
        }
    }

    int top() {
        if(head){
            return head->val;
        }
        return INT_MAX;
    }

    int getMin() {
        if(head){
            return (mp.begin())->first;
        }
        return INT_MAX;
    }
};
