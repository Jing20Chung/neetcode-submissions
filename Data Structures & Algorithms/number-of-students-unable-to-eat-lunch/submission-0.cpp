// 0 = circular
// 1 = square

// students are standing in a queue
// sandwiches are placed in a stack
// num of sandwiches == num of students

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        for(int type: students) {
            count[type]++;
        }

        for(int type: sandwiches) {
            if (count[type] == 0) break;
            count[type]--;
        }
        return count[0] + count[1];
    }
};