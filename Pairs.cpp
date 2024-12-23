#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> pairsBruteforce(vector<int> vec,int target) {  //O(n ^ 2)
  vector<int> ans;
  for(int i=0;i<vec.size();i++) {
    for(int j = i + 1;j<vec.size();j++) {
        if(vec[i] + vec[j] == target) {
           ans.push_back(i);
           ans.push_back(j);
           return ans;
        }
    }
   
  }
   return vector<int>();
}
vector<int> pairs(int target,vector<int> vec) {   //O(n)
    vector<int> ans;
    for(int i = 0,j = vec.size() - 1;i < vec.size();) {
        if((vec[i] + vec[j]) > target) {
            j--;
        }else if((vec[i] + vec[j]) == target) {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }else{
            i++;
        }
    }
    return vector<int> ();
}
int main () {
 vector <int> vec = {2,8,9,11,12};
 sort(vec.begin(),vec.end());
 cout << " using brute force approach : " ;
 for(auto i : pairsBruteforce(vec,20)){
    cout << i << " ";
 }
 cout << endl;
 cout << " using optimized approach : " ;
 for(auto i : pairs(20,vec)){
    cout << i << " ";
 }
 return 0;
}
