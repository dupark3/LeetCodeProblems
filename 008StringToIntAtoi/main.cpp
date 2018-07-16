#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isWhiteSpace(char c){
        return (c >= 9 && c <=11) || c == 32;
    }

    bool isNumeric(char c){
        return c >= 48 && c <= 57;
    }

    int myAtoi(string str) {
        size_t size = str.size();        
        int i = 0;
        int result = 0;
        int negate = 1;

        // skip whitespaces if any
        while (i < size && isWhiteSpace(str[i])){
            ++i;
        }
                
        // skip + sign if any. store negative sign if any
        if (str[i] == 43){
            ++i;
        } else if (str[i] == 45){
            negate = -1;
            ++i;
        }
        
        while (i != size && isNumeric(str[i])){
            if (negate == -1 && result * -1 < INT_MIN/10){
                return INT_MIN;
            } else if (result > INT_MAX / 10){
                return INT_MAX;
            }
            result = (result * 10) + str[i] - 48;
            ++i;
        }
        
        return result * negate;
    }
};

int main() {
    Solution solution;
    string input = "42";
    cout << solution.myAtoi(input) << endl;
    cout << solution.myAtoi("   42") << endl;
    cout << solution.myAtoi("\t42extra") << endl;
    cout << solution.myAtoi("\t         -42extra") << endl;
    cout << solution.myAtoi("\ninvalid42") << endl;
    cout << solution.myAtoi("\n-4444444444444444442") << endl;
    cout << solution.myAtoi("\n+4444444444444444442") << endl;
    cout << solution.myAtoi("2147483648") << endl;
    return 0;
}