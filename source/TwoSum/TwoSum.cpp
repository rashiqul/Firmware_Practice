/*
 * Problem Statement: Two Sum
 * Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up 
 * to the target. You may assume that each input has exactly one solution, and you may not use the same element twice. 
 * The solution should have an efficient time complexity.
 *
 * Example:
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1]
 * Explanation: nums[0] + nums[1] = 2 + 7 = 9, so we return [0, 1].
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TwoSum 
{
    public:
        /* Function to find indices of two numbers that add up to the target*/
        vector<int> twoSum(vector<int>&nums, int target)
        {
            int complement = 0;
            
            /* Map to store numbers and their indices*/
            unordered_map<int, int> numToIndex;
            for(int i = 0; i < nums.size(); i++)
            {
                /* Calculate the complement */
                complement = target - nums[i];
                 /* Check if the complement is already in the map */
                if (numToIndex.find(complement) != numToIndex.end())
                {
                    return {numToIndex[complement], i};
                }
                else
                {
                    /* Add the number and its index to the map */
                    numToIndex[nums[i]] = i;
                }
            }
            return {};
        }   
};

void TwoSumMain()
{
    TwoSum twoSum;

    // Test Case 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum.twoSum(nums1, target1);
    std::cout << "Indices: " << result1[0] << " " << result1[1] << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {1, 5, 3, 4, 6};
    int target2 = 10;
    std::vector<int> result2 = twoSum.twoSum(nums2, target2);
    std::cout << "Indices: " << result2[0] << " " << result2[1] << std::endl;

    // Test Case 3
    std::vector<int> nums3 = {1, 2, 3, 4, 5};
    int target3 = 10;
    std::vector<int> result3 = twoSum.twoSum(nums3, target3);
    if (!result3.empty()) {
        std::cout << "Indices: " << result3[0] << " " << result3[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    // Test Case 4
    std::vector<int> nums4 = {1, 5, 5, 3, 7};
    int target4 = 10;
    std::vector<int> result4 = twoSum.twoSum(nums4, target4);
    std::cout << "Indices: " << result4[0] << " " << result4[1] << std::endl;

    // Test Case 5
    std::vector<int> nums5 = {-3, 4, 3, 90};
    int target5 = 0;
    std::vector<int> result5 = twoSum.twoSum(nums5, target5);
    std::cout << "Indices: " << result5[0] << " " << result5[1] << std::endl;

    // Test Case 6
    std::vector<int> nums6 = {-5, -7, -3, -2};
    int target6 = -10;
    std::vector<int> result6 = twoSum.twoSum(nums6, target6);
    std::cout << "Indices: " << result6[0] << " " << result6[1] << std::endl;

    // Test Case 7
    std::vector<int> nums7 = {1000000, 2500000, 3000000, -1500000};
    int target7 = 1000000;
    std::vector<int> result7 = twoSum.twoSum(nums7, target7);
    std::cout << "Indices: " << result7[0] << " " << result7[1] << std::endl;

    // Test Case 8
    std::vector<int> nums8 = {5};
    int target8 = 5;
    std::vector<int> result8 = twoSum.twoSum(nums8, target8);
    if (!result8.empty()) {
        std::cout << "Indices: " << result8[0] << " " << result8[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    // Test Case 9
    std::vector<int> nums9 = {3, 3, 4, 5};
    int target9 = 6;
    std::vector<int> result9 = twoSum.twoSum(nums9, target9);
    std::cout << "Indices: " << result9[0] << " " << result9[1] << std::endl;

    // Test Case 10
    std::vector<int> nums10 = {1, 2};
    int target10 = 3;
    std::vector<int> result10 = twoSum.twoSum(nums10, target10);
    std::cout << "Indices: " << result10[0] << " " << result10[1] << std::endl;
}