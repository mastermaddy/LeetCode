class Solution{
private:
  int MAX_CHAR = 26;
  bool isValid(vector<int> count, int k){
    int val = 0;
    for (int i=0; i<MAX_CHARS; i++){
      if (count[i] > 0)
        val++;  
    }
    return (k >= val);
  }
public:
  string longestSubstringWithKUniqueChars(string s, int k){
    vector<int> count(MAX_CHARS,0);
    int maxSubstringLength = 1, startOfMaxSubstring = 0;
    int currStart = 0, currEnd = 0;
    count[s[0]-'a']++;
    for(int i=1;i<s.size();++i){
      count[s[i]-'a']++;
      currEnd++;
      while (!isValid(count, k)){
        count[s[currStart]-'a']--;
        currStart++;
      }
      if (currEnd-currStart+1 > max_window_size){
        maxSubstringLength = currEnd-currStart+1;
        startOfMaxSubstring = currStart;
      }
    }
    return s.substr(startOfMaxSubstring, maxSubstringLength);
  }
};
