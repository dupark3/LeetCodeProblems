#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copyofNums1 = nums1;
        int numberOfEmpties = nums1.size() - m;
        auto firstIterator = copyofNums1.begin();
        auto secondIterator = nums2.begin();
        auto destinationIterator = nums1.begin();

        while(destinationIterator != nums1.end()){
            if (firstIterator == copyofNums1.end() - numberOfEmpties && secondIterator != nums2.end()){
                *destinationIterator = *secondIterator;
                ++secondIterator;
            }
            else if (secondIterator == nums2.end() && firstIterator != copyofNums1.end() - numberOfEmpties){
                *destinationIterator = *firstIterator;
                ++firstIterator;
            }
            else {
                if (*firstIterator < *secondIterator){
                    *destinationIterator = *firstIterator;
                    ++firstIterator;
                } else {
                    *destinationIterator = *secondIterator;
                    ++secondIterator;
                }
            }
            ++destinationIterator;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 3, 6, 0, 0, 0};
    vector<int> nums2 = { 2, 5, 8 };
    int m = 3;
    int n = 3;
    solution.merge(nums1, m, nums2, n);

    for (int i = 0; i != nums1.size(); ++i){
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}