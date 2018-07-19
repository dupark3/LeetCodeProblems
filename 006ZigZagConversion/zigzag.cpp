#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        size_t string_size = s.size();
        string result;
        int complement = numRows - 1;
        for (int current_row = 0; current_row != numRows; ++current_row){
            if (current_row != numRows - 1 && current_row != 0){
                // all rows other than the first and last row
                for (int i = current_row, count = 0; i < string_size; ++count){
                    result += s[i];
                    if (count % 2 == 0){
                        i += (numRows - 2) * 2 - (current_row) * 2 + 2;
                    } else {
                        i += (numRows - 2) * 2 - (current_row + complement) * 2 + 2;
                    }
                }
            } else {
                // last row does not obey above law as the increment turns to zero
                // first row behaves just like last row, so follow this logic
                for (int i = current_row; i < string_size;
                    i += (numRows - 2) * 2 + 2){
                    result += s[i];
                }
            }
            complement -= 2;
        }

        return result;
    }
};

int main() {
    Solution solution;
    string input1 = "A";

    cout << solution.convert(input1, 1) << endl;

    return 0;
}