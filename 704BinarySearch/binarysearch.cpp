#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int search(vector<int>& ints, int k) {
        int size = ints.size();
        int left = 0;
        int right = size;
        int i = size / 2;
        
        while (right != left && right != left + 1){
            cout << "right : " << right << " left : " << left << " i : " << i << endl;
            if (k == ints[i]){
                return i;
            } else if (k < ints[i]){
                cout << "   going left " << endl;
                right = i;
                i = left + ((i - left) / 2);
            } else if (k > ints[i]){
                cout << "   going right " << endl;
                left = i + 1;
                i = i + ((right - i) / 2);
            }
        }
        if (ints[i] == k){
            return i;
        } else {
            return -1;
        }
        
    }
};

int main(){
    vector<int> ints = {-1,0,3,5,9,12};
    Solution solution;
    cout << solution.search(ints, 9);

    return 0;
}