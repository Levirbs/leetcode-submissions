class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (const string& c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/"){
                int second = nums.top(); nums.pop();
                int first = nums.top(); nums.pop();
                int num;

                switch (c[0]) {
                    case '+': num = first + second; break;
                    case '-': num = first - second; break;
                    case '*': num = first * second; break;
                    case '/': num = first / second; break;
                }

                nums.push(num);

            } else {
                nums.push(stoi(c));
            }
        }
        return nums.empty() ? 0 : nums.top();
    }
};
