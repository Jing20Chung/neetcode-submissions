class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q(students.begin(), students.end());

        int idx = 0;
        int rotation = 0;
        while(!q.empty() && rotation < q.size()) {
            if (q.front() == sandwiches[idx]) {
                rotation = 0;
                q.pop();
                idx++;
            }
            else {
                q.push(q.front());
                q.pop();
                rotation++;
            }
        }
        return q.size();
    }
};