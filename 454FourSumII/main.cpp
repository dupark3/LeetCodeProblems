#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        size_t ASize = A.size();
        size_t BSize = B.size();
        size_t CSize = C.size();
        size_t DSize = D.size();

        int total = 0;

        unordered_map<int, int> hashmap;

        for (int i = 0; i != ASize; ++i){
            for (int j = 0; j != BSize; ++j){
                ++hashmap[A[i] + B[j]];
            }
        }

        for (int i = 0; i != CSize; ++i){
            for (int j = 0; j != DSize; ++j){
                int inverseSum = (C[i] + D[j]) * -1;
                auto iterator = hashmap.find(inverseSum);
                if (iterator != hashmap.end()){
                    total += iterator->second;
                }
            }
        }

        return total;
    }
};

int main(){
    Solution solution;
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    cout <<solution.fourSumCount(A, B, C, D) << endl;
    return 0;
}