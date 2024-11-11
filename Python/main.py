"""

This document provides a list of sample questions and concepts that are commonly covered in embedded-software/firmware 
interviews. The questions are designed to test the candidate's understanding of fundamental programming concepts and 
their ability to apply them to real-world problems. The solutions are provided in Python, a popular language for 
embedded systems development due to its versatility and ease of use.
========================================================================================================================

1. String Manipulation
Example Question: Implement a function to determine if a string is a palindrome (ignoring spaces, punctuation, and case).
Concepts Covered: String traversal, string filtering, case conversion.
Why Relevant: String parsing could be useful in interpreting logs or messages in SDV systems.

2. Array Manipulation
Example Question: Given an array of integers, return a new array such that each element at index i is the product of all 
                  the numbers in the original array except the one at i.
Concepts Covered: Array traversal, prefix/suffix products, space optimization.
Why Relevant: Arrays are fundamental in integration and data transformation.

3. Searching & Sorting
Example Question: Implement binary search to find the target element in a sorted array.
Concepts Covered: Searching algorithms, edge case handling (e.g., empty arrays).
Why Relevant: Searching is often required in data lookup, which could be useful in the platform software context.

4. Linked List Operations
Example Question: Reverse a singly linked list.
Concepts Covered: Linked list traversal, in-place reversal.
Why Relevant: Linked lists are common in system-level programming and data structures for communication protocols.

5. Hashing and Sets
Example Question: Find the first non-repeating character in a string.
Concepts Covered: Hash maps, set operations, efficient lookups.
Why Relevant: Hashing can help handle unique identifiers or messages in SDV communications.

6. Queue/Stack-based Questions
Example Question: Implement a function to evaluate a given postfix expression.
Concepts Covered: Stack operations, parsing.
Why Relevant: Useful for interpreting and evaluating complex expressions or signals in vehicle systems.

7. Basic Dynamic Programming
Example Question: Given a list of non-negative integers representing the amount of money in each house, find the maximum 
                  amount you can rob without robbing two adjacent houses (House Robber Problem).
Concepts Covered: Dynamic programming, optimization.
Why Relevant: Helps understand state optimization, useful in resource management for SDVs.

8. Matrix/2D Array Traversal
Example Question: Write a function to find the number of islands in a given 2D binary matrix (connected components).
Concepts Covered: Matrix traversal, DFS/BFS.
Why Relevant: Matrix representation could be used in mapping SDV data or configurations.

9. Basic Graph Algorithms
Example Question: Given a list of connections between nodes, determine if a path exists between two nodes in an 
                  undirected graph.
Concepts Covered: Graph traversal, BFS/DFS.
Why Relevant: Graph algorithms are crucial for vehicle communication networks and route planning.

10. String Parsing for Logs or Messages
Example Question: Parse a log file and identify patterns, e.g., extract error codes or trace IDs.
Concepts Covered: String manipulation, regular expressions.
Why Relevant: Helpful for debugging or analyzing logs in SDV systems.

"""
import Palindrome
import ProductExceptSelf
import BinarySearch
import NonRepeatChar

if __name__ == "__main__":

    """
    Palindrome Check
    """
    print("Palindrome Check:")
    # Output: True
    print(Palindrome.is_palindrome("A man, a plan, a canal: Panama")) 
    # Output: False 
    print(Palindrome.is_palindrome("race a car"))

    """
    Array Manipulation
    """
    print("\nProduct Except Self:")

    # Output: [24, 12, 8, 6]
    print(ProductExceptSelf.product_except_self([1, 2, 3, 4]))
    # Output: [60, 40, 30, 24]
    print(ProductExceptSelf.product_except_self([2, 3, 4, 5]))

    """
    Binary Search
    """
    print("\nBinary Search:")

    # Output: 3
    print(BinarySearch.binary_search([1, 2, 3, 4, 5, 6], 4))

    """
    First Non-Repeating Character
    """
    print("\nNon-Repeating Character:")

    # Output: 0
    print(NonRepeatChar.first_non_repeating_char("leetcode"))
    # Output: -1  
    print(NonRepeatChar.first_non_repeating_char("aabb"))     
