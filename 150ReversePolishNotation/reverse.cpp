#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
//// "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0){
            return 0;
        } else if (tokens.size() == 1){
            return tokens[0];
        }
        stack<int> mystack;

        auto it = tokens.begin();
        while(it != tokens.end()){
            // push until operator found
            while(isNumeric(*it)){
                mystack.push(stoi(*it));
                ++it;
            }
            
            // consume two with operator
            int y = mystack.top();
            mystack.pop();
            int x = mystack.top();
            mystack.pop();

            // push onto stack the computed answer
            mystack.push(compute(x, y, *it++));
        }

        return mystack.top();
    }
private:
    bool isNumeric(string& str){
        if (str.size() > 1 || isdigit(str[0])){
            return true;
        } else {
            return false;
        }
    }

    int compute(int x, int y, string& oper){
        if (oper == "+") return x + y;
        if (oper == "-") return x - y;
        if (oper == "/") return x / y;
        if (oper == "*") return x * y;
    }
};

int main(){
    Solution solution;
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    vector<string> tokens2 = {"2","1","+","3","*"};
    vector<string> tokens3 = {"2","1","+","3","2", "+", "/"};

    cout << solution.evalRPN(tokens) << endl;
    cout << solution.evalRPN(tokens2) << endl;
    cout << solution.evalRPN(tokens3) << endl;

    return 0;
}