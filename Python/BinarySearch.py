# Searching & Sorting
# -------------------
# Example Question: Implement binary search to find the target element in a sorted array.
# Concepts Covered: Searching algorithms, edge case handling (e.g., empty arrays).
# Why Relevant: Searching is often required in data lookup, which could be useful in the platform software context.

def binary_search(nums, target):
    """
    Implement binary search to find the target element in a sorted array
    """
    # Get length of the array
    length = len(nums)
    
    # Initialize the low and high pointers
    low = 0
    high = length - 1

    # Edge case handling, empty array
    if length == 0:
        return -1
    while (low <= high):
        # Calculate the middle index
        mid = (low + (high - low) // 2)
        
        # Check if the target is found at the middle index
        if (nums[mid] == target):
            return mid    
        # Search in the left half
        elif (nums[mid] > target):
            high = mid - 1
        # Search the right half
        else:
            low = mid + 1
    
    return -1

