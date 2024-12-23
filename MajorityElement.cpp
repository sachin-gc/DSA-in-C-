#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
int maxelement(array<int,6> a,int n) {
  
  for(int i : a) {
    int ele = i;
    int freq = 0;
    for(int j : a){
       if(j == ele) {
        freq++;
       }
       if(freq > n/2) {
        return ele;
       }
    }
  }
  return -1;
}
int maxsorting(array<int,6> a , int n) {
   int fr = 1;
   int arr[] = {a.at(0)};
   for(int i=1;i<a.size();i++) {
    if(a[i] == a[i - 1]){
        fr++;
        if(fr > n/2) {
            return a[i];
        }
    }else{
        fr = 1;
        arr[0] = a[i];
    }
    
   }
   return -1;
}
int majorityElement(vector<int> nums) {   //Moor's algorithm O(n)
        int ans = 0,freq = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(freq == 0) {
                ans = nums[i];
            }
            if(ans == nums[i]) {
                freq++;
            }else{
                freq--;
            }
        }
        return ans;
    }
int main() {
   array<int,6> a = {1,2,5,2,2,2};
   vector<int> vec = {1,5,4,5,5,5,4,2,5};
   cout<< "majority element using brute force is : " << maxelement(a,a.size()) << endl;
   //sort(a.begin(),a.end());
   //cout << "majorityr ele using sorting : " << maxsorting(a,a.size()) << endl;
   cout<< "majority element using moore's algorithm is : " << majorityElement(vec) << endl;

    return 0;
}
