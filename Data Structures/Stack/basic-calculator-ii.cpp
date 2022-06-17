class Solution {
public:
    int calculate(string s) {
        stack<int> evaluation;
        int num = 0, total = 0, sz = s.size();
        char sign = '+';
        for(int i=0;i<sz;++i){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }
            if(!isdigit(s[i]) && s[i]!=' ' || i == sz-1){
                if(sign=='+'){
                    evaluation.push(num);
                }
                else if(sign=='-'){
                    evaluation.push(-num);
                }
                else{
                    if(sign=='*') num = evaluation.top()*num;
                    else if(num!=0) num = evaluation.top()/num;
                    evaluation.pop();
                    evaluation.push(num);
                }
                num = 0;
                sign = s[i];
            }
        }
        while(!evaluation.empty()){
            total += evaluation.top();
            evaluation.pop();
        }
        return total;
    }
};
