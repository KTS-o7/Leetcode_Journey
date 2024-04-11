class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> result(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string str;
        for (int i = 0; i < result.size(); ++i) {
            if (str.empty() && result[i] == 0) continue;
            str.push_back(result[i] + '0');
        }
        return str;
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n+m)
// Code logic explained :
// 1. If any of the number is 0 then return 0.
// 2. Create a vector result of size num1.size() + num2.size() and initialize all the elements to 0.
// 3. Traverse from the unit's place of num1 and num2 and multiply the two numbers and add the result to the result vector.
// 4. sum = mul + result[i + j + 1] is done so as to add the carry from the previous multiplication, if it exists.
// 5. result[i + j + 1] = sum % 10 is done to store the unit's place of the result.
// 6. result[i + j] += sum / 10 is done to store the carry of the result.
// 7. Traverse through the result vector and store the result in a string and return the string.