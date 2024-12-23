#include<iostream>
#include<array>
using namespace std;
// namespace std;
void printSubarray(array <int,5> array,int size) {
    for(int i = 0;i < size ; i++) {
        for(int j = i;j < size;j++) {
            for(int k = i;k <= j;k++) {
                cout << array[k];
            }
            cout << " ";
        }
        cout << endl;
    }
}
void maxSubarraySum(array <int,5> array,int size) { //takes tc : O(N^2)
    int sum = 0;
    int maxSum = INT_MIN;
     for(int i = 0;i < size ; i++) {
        sum = 0;
        for(int j = i;j < size;j++) {
            sum+=array[j];
            maxSum = max(maxSum,sum);
    }

}
cout << "the max sum of subarray is : " << maxSum << endl;
}
void kadanesalgo(array <int,5> array, int size) {
    int cursum = 0,maxsum = INT_MIN;
 for(int i = 0; i<size;i++) {
   cursum += array[i];
   maxsum = max(maxsum,cursum);
   if(cursum < 0) {
    cursum = 0;
   }

 }
 cout << " max sum is : " << maxsum << endl;
}
int main () {
    array <int,5> arr = {1,5,4,2,-9};
    printSubarray(arr,5);
    maxSubarraySum(arr,5);
    kadanesalgo(arr,5);
    return 0;

}
