#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        return concat(nums);
    }

    static bool compare(int a_int, int b_int){
        if (a_int == b_int){
            cout << "same "<< endl;
            return false;
        }

        string a = to_string(a_int);
        string b = to_string(b_int);
        cout << "comparing " << a << " and " << b << endl;
        
        cout << " test " << endl;
        int a_size = a.size();
        int b_size = b.size();

        for(int i = 0, j = 0; i != a_size || j != b_size; ++i, ++j){
            if (i == a_size && j != b_size){
                cout << "   i is at the end " << endl;
                if (a[0] != b[j]){
                    return a[0] > b[j]; 
                } else {
                    return a[0] > b[j-1]; 
                }
                
            } else if (j == b_size && i != a_size){
                cout << "   j is at the end , " << a[i] << " and " << b[0] << endl;
                if (a[i] != b[0]){
                    return a[i] > b[0];
                } else {
                    return b[0] < a[i-1];
                }
                
            } else if (i == a_size - 1 && j == b_size - 1){
                //cout << "   returning " << i << " and " << j << endl;
                return a[i] > b[j];
            } 
            if (a[i] != b[j]){
                //cout << "   different at " << i << " and " << j << endl;
                return a[i] > b[j];
            }
        }   
    }

    string concat(vector<int>& nums){
        string result;
        int numsSize = nums.size();
        for (int i = 0; i != numsSize; ++i){
            result += to_string(nums[i]);
        }
        cout << "concat done" << endl;
        return result;
    }
};

int main(){
    Solution solution;

    //vector<int> nums = {0, 9, 32, 342, 34, 30, 33, 333, 35, 35, 35, 3535, 350, 345, 95, 90, 5}; // 9 95 900 5 34 3 32
    vector<int> nums2 =  {212, 21}; // 212 21
    vector<int> nums = {242, 24}; // 24 242 if last digit == first digit,  
    // singular digits go first within that number, so 9 before 95 or 900
    // nope, digits can be increasing or decreasing, like 95 or 59. 59 would go before 5.
    // first will be the number with the largest first digit that is either increasing, single/constant, or decreasing
    // if first digit is greater than the digit after that one, 
    // 59 55 555 523 52 522 520 50

    cout << solution.largestNumber(nums) << endl;
    return 0;
}