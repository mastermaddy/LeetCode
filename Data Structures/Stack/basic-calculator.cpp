class Solution {
public:
    int calculate(string s) {
        int total = 0, sign = 1, num = 0;
        stack<int> signs({1});
        for(auto c:s){
            if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            else{
                if(c=='-' || c== '+'){
                    total = total + sign*num*signs.top();
                    num = 0;    
                    sign = c=='+'?1:-1;
                }
                if(c=='('){
                    signs.push(sign*signs.top());
                    sign = 1;
                }
                if(c==')'){
                    total = total + signs.top() * sign * num;
                    num = 0;
                    signs.pop();
                    sign = 1;
                }
            }
        }
        total += sign*num*signs.top();
        return total;
    }
};
