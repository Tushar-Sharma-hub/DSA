//Number of Students Unable to Eat Lunch
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int> std;
        for(int i=0;i<students.size();i++){
            std.push(students[i]);
        }
        int count=0,i=0;
        while(std.size()!=0 && count<n){
            if(sandwiches[i]==std.front()){
                std.pop();
                count=0;
                i++;
            }
            else{
                std.push(std.front());
                std.pop();
                count++;
            }
        }
        return std.size();
    }
};