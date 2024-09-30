class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());

        int i = 0;
        int j = 0;
        int cnt = 0;

        while(i<students.size())
        {
            if(seats[i] == students[j]) {
                i++;j++;
            }
            else{
                if(seats[i] < students[j]) {
                    students[j]--;cnt++;
                }
                else if(seats[i] > students[j]) {
                    students[j]++;cnt++;
                }
            }
        }
        return cnt;
    }
};