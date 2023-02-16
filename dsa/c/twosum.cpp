#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// vector<int> twoSum(vector<int>& nums, int target) {
//    unordered_map<int,int> mp;
//        int n=nums.size();
//        vector<int> ans;
//        for(int i=0;i<n;i++)
//        {
//            if(mp.find(target-nums[i])!= mp.end())
//            {
//                ans.push_back(i);
//                ans.push_back(mp[target-nums[i]]);
//            }
//            else
//                mp[nums[i]]=i;
//        }
//
//        return ans  ;
//    }

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        for(int i=0; i < nums.size(); i++){
            for(int j=i+1;j<nums.size( ) ; j++){
                if(nums[j] == target-nums[i]){
                    ans.push_back(i) ;
                    ans.push_back(j) ;
                    break;
                }
            }
        }
        return ans;
    }
};

    int main(){
//        vector<int> res;
        vector<int> a = {1,4,5,7,8,23,6};
//        for(int &x : twoSum(a,9))
//            cout << x << endl;
//        cout << "\n";
        Solution s;
        for (int &x: s.twoSum(a,9))
            cout << x ;

        return 0;
    }
