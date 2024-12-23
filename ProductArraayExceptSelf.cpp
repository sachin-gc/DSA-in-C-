#include<iostream>
#include<vector>
using namespace std;
 vector<int> productExceptSelfnsquare(vector<int>& nums) { // O(n^2)

        vector<int> answers(nums.size(),1);
        for(int i = 0;i < nums.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i != j) {
                    answers[i] *= nums[j]; 
                }
            }
        }
        return answers;
    }
vector<int> productExceptSelf(vector<int>& nums) { // O(n)
      vector<int> ans(nums.size(),1);
      vector<int> prefixarray(nums.size(),1);
      vector<int> suffixarray(nums.size(),1);
      for(int i = 1; i<nums.size(); i++) {
        prefixarray[i] = prefixarray[i - 1] * nums[i - 1];
      }
      for(int i = nums.size() - 2; i>=0; i--) {
        suffixarray[i] = suffixarray[i + 1] * nums[i + 1];
      }
      for(int i = 0; i < nums.size(); i++) {
        ans[i] = prefixarray[i] * suffixarray[i];
      }
      return ans;

    }
    vector<int> productExceptSelfreducingsc(vector<int>& nums) { // O(n) and reducing space complexity
      vector<int> ans(nums.size(),1);
      
      for(int i = 1; i<nums.size(); i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
      }
      int suffix = 1;
      for(int i = nums.size() - 2; i>=0; i--) {
        suffix*= nums[i + 1];
        ans[i]*=suffix;
      }
     return ans;

    }
int main() {
    vector<int> vec = {1,2,3,4};
    cout << " product array is : ";
    vector<int> ans = productExceptSelfreducingsc(vec);
    for(int i = 0;i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
