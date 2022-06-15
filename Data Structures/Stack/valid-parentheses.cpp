class Solution {
private:
    unordered_map<char,char> bracketsPair = {{'(',')'}, {'[',']'}, {'{','}'}};
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(bracketsPair.find(c)!=bracketsPair.end()){
                st.push(c);
            }
            else{
                if(!st.empty()){
                    if(bracketsPair[st.top()]!=c){
                        return false;
                    }
                    else{
                        st.pop();
                    }    
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
