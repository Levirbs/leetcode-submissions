class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        int first, second;
        for (string token : tokens) {
            if (token == "+") {
                first = nums.top(); nums.pop(); second = nums.top(); nums.pop();
                nums.push(first + second);
            } else if (token == "-") {
                first = nums.top(); nums.pop(); second = nums.top(); nums.pop();
                nums.push(second - first);
            } else if (token == "*") {
                first = nums.top(); nums.pop(); second = nums.top(); nums.pop();
                nums.push(first * second);
            } else if (token == "/") {
                first = nums.top(); nums.pop(); second = nums.top(); nums.pop();
                nums.push(second / first);
            } else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};
