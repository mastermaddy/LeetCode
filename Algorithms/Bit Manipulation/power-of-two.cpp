class Solution {
public:
    bool isPowerOfTwo(int n) {
        unsigned int count = 0;
        while(n>0) {
            n &= (n - 1);
            count++;
        }
        return count==1?true:false;
    }
};
