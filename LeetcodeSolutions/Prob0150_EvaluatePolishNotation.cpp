class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        stack<int> st;
        int l = tokens.size();
    
        for(int i=0;i<l;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||tokens[i] == "/"){
                int operator2 = st.top();
                st.pop();
                int operator1 =  st.top();
                st.pop();

                int tempResult;
                if(tokens[i] == "+"){
                    tempResult = (operator1 + operator2);
                }
                else if(tokens[i] == "-"){
                    tempResult = (operator1 - operator2);
                }
                else if(tokens[i] == "*"){
                    tempResult = (operator1 * operator2);
                }
                else if(tokens[i] == "/"){
                    tempResult = (operator1 / operator2);
                }

                st.push(tempResult);

            }
            else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};

// time complexity: O(n)
// space complexity: O(n)
/*code explained :
Initialize Variables:

Initialize an empty stack st to hold operands during evaluation.
Get the size l of the input vector tokens.
Set up I/O optimizations for faster execution.
Iterate Through Tokens:

Use a loop to iterate through each token in the tokens vector.
For each token:
Check if the token is an operator (+, -, *, /) by comparing it with these strings.
If it is an operator:
Pop the top two elements from the stack (operator2 and operator1).
Evaluate the result based on the operator:
If the operator is +, calculate tempResult = operator1 + operator2.
If the operator is -, calculate tempResult = operator1 - operator2.
If the operator is *, calculate tempResult = operator1 * operator2.
If the operator is /, calculate tempResult = operator1 / operator2.
Push the tempResult back onto the stack.
If it is not an operator:
Convert the token to an integer using stoi() and push it onto the stack.
Return Result:

After processing all tokens, the final result is at the top of the stack.
Return the top element of the stack as the result of the evaluation.
This algorithm uses a stack to simulate the evaluation of a reverse Polish notation (RPN) expression, where operators come after their operands. The provided code efficiently handles the operators and operands, evaluating the expression and returning the final result.*/