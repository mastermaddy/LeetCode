class Solution {
public:
    int calculate(string s) {
        int total = 0, num = 0, sz = s.size();
        char sign = '+';
        stack<int> eval;
        for(int i=0;i<sz;++i){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }
            if(!isdigit(s[i]) && s[i]!=' ' || i==sz-1){
                if(sign=='+'){
                    eval.push(num);
                }
                else if(sign=='-'){
                    eval.push(-num);
                }
                else{
                    if(sign=='*'){
                        num = eval.top()*num;
                    }
                    else{
                        num = eval.top()/num;
                    }
                    eval.pop();
                    eval.push(num);
                }
                num = 0;
                sign = s[i];
            }
        }
        while(!eval.empty()){
            total += eval.top();
            eval.pop();
        }
        return total;
    }
};
