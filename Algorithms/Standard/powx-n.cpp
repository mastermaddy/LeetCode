class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double pow = myPow(x, n/2);
        if(n%2){
            return n<0 ? 1/x*pow*pow : x*pow*pow;
        }
        else{
            return pow*pow;
        }
    }
};
