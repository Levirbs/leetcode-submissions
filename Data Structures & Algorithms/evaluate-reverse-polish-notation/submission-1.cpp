class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        int first, second;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                first = nums.top(); nums.pop(); 
                second = nums.top(); nums.pop();

                switch(token[0]) {
                    case '+': nums.push(first + second); break;
                    case '-': nums.push(second - first); break;
                    case '*': nums.push(first * second); break;
                    case '/': nums.push(second / first); break;
                }

            } else {
                nums.push(stoi(token));

            }
        }
        return nums.top();
    }
};
