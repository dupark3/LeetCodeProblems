#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        vector<int>::iterator trail = nums.begin();
        vector<int>::iterator lead = trail + 1;
        int size = 1;

        while (lead != nums.end()){
            if (*lead != *trail){
                ++size;
                if (lead != ++trail){
                    swap(trail, lead);
                }
            } 
            ++lead;
        }

        return size;
    }

    void swap(vector<int>::iterator x, vector<int>::iterator y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
};

int main(){
    Solution solution;
    vector<int> sortedNums = {0, 1, 2, 3, 4, 4, 4, 5, 6};

    int newSize = solution.removeDuplicates(sortedNums);

    cout << "Size of array without duplicates is " 
         << newSize << endl;
    for (int i = 0; i != newSize; ++i){
        cout << sortedNums[i] << " ";
    }
    cout << endl;
    

    return 0;
}