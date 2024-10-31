# Array Manipulation
# ------------------
# Example Question: Given an array of integers, return a new array such that each element at index i is the product of 
#                   all the numbers in the original array except the one at i.
# Concepts Covered: Array traversal, prefix/suffix products, space optimization.
# Why Relevant: Arrays are fundamental in integration and data transformation.

def product_except_self(nums):
    """
    Function to return a new array such that each element at index i is the product of all the numbers in the original
    array except the one at i
    """
    # Get length of the array
    length = len(nums)
    
    # Empty list to store the result
    result  = [1] * length
    
    # Initialize the product variables
    prefix_product = 1
    suffix_product = 1

    # Traverse the array and calculate the prefix product
    for i in range(length):
        result[i] = prefix_product
        prefix_product *= nums[i]
    
    # Tracerse the array in reverse and calculate the suffix product
    for i in range(length-1, -1, -1):
        result[i] *= suffix_product
        suffix_product *= nums[i]

    return result       
        