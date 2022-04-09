class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int countStudent = 0;
        vector<int> studentChoice(2,0);
        for(auto student:students){
            studentChoice[student]++;
            countStudent++;
        }
        for(auto sandwich:sandwiches){
            if(studentChoice[sandwich]){
                studentChoice[sandwich]--;
                countStudent--;
            }
            else{
                break;
            }
        }
        return countStudent;
    }
};
