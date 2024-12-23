#include<iostream>
#include<vector>
using namespace std;

int maxWater(vector<int> vec){  //brute force method  O(n^2)
int maxwater = 0;
   for(int i = 0; i<vec.size() ; i++) {
    for(int j = i + 1;j<vec.size(); j++) {
        int length = min(vec.at(i),vec.at(j));
        int width  = j - i;
        maxwater = max(maxwater,length * width);
    }
   }
 return maxwater;
   
}
int maxArea(vector<int>& height) {   // O(n) two pointer approach
        int maxwater = 0;
        int left = 0,right = height.size() - 1;

        while(left < right) {
            int h = min(height[left],height[right]);
            int w = right - left;
            maxwater = max(maxwater,h * w);
            height[left] < height[right]? left++:right--;
        }
        return maxwater;
}
   
   
int main() {
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    cout << " maximum water between poles are : " << maxWater(vec) << endl;
    cout << " maximum water between poles are : " << maxArea(vec) << endl;

    return 0;
}
