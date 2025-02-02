#include <iostream>

using namespace std;

class Solution{
public:

    bool check(vector<int>& nums){
        int numUnordered = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                numUnordered+= 1;
            }
            if(numUnordered > 1){
                return false;
            }
        }
        if(numUnordered == 1 && nums[0] < nums[nums.size()-1]){
            return false;
        }
        return true;
    }
};