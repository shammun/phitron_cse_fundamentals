/*

https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/

Maximum Product of Two Elements in an Array

Given the array of integers nums, you will choose two different indices i and j of 
that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the 
maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the 
maximum value of (5-1)*(5-1) = 16.


*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_first = 0;
        int max_second = 0;

        for(int num : nums){
            if(num > max_first){
                max_second = max_first;
                max_first = num;
            } else if(num > max_second){
                max_second = num;
            }
        }

        return (max_first - 1) * (max_second - 1);
    }
};