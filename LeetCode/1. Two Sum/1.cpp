using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i = 0; i<size; i++){
            for(int ii = 0; ii<size; ii++){
                if (nums[i]+nums[ii]==target&& i != ii){
                    return {i, ii};
                }
            }
        }
        return {};
        
    }
};