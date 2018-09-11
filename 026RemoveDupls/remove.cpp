#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
    }
};

int main(){
    Solution solution;
    vector<int> sortedNums = {0, 0, 0, 1, 1, 2, 3, 5, 6, 6};
    
    int newSize = solution.sortedNums;

    cout << "Size of array without duplicates is " 
         << newSize << endl;
    for (int i = 0; i != newSize; ++i){
        cout << sortedNums[i] << " ";
    }
    cout << endl;
    

    return 0;
}