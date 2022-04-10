class Solution {
public:
    int findMajorProvince(int province, vector<int>& parentProvince) {
        return parentProvince[province] == province ? province : findMajorProvince(parentProvince[province], parentProvince);
    }
    
    void mergeProvinces(vector<int>& parentProvince, int city1, int city2, int &numOfProvinces){
        int parent1 = findMajorProvince(city1, parentProvince);
        int parent2 = findMajorProvince(city2, parentProvince);
        if (parent1 != parent2) {
            parentProvince[parent2] = parent1;
            numOfProvinces--;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int len = isConnected.size();
        vector<int> parentProvince(len, 0);
        for (int i = 0; i < len; i++){
            parentProvince[i] = i;
        }
        int numOfProvinces = len;  
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {   
                if (isConnected[i][j] > 0) {
                    mergeProvinces(parentProvince, i, j, numOfProvinces);
                }
            }
        }
        return numOfProvinces;
    }
};
