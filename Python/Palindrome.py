# String Manipulation
# -------------------
# Question: Implement a function to determine if a string is a palindrome 
# (ignoring spaces, punctuation, and case).
#
# Concepts Covered: String traversal, string filtering, case conversion.
# Why Relevant: String parsing could be useful in interpreting logs or messages in SDV systems.

def is_palindrome(expression: str)-> bool:
    """
    Function to determine if a string is a palindrome
    """
    filtered_expression = []

    # Filter out spaces and punctuation
    for char in expression:
        # Check if character is alphanumeric
        if char.isalnum():
            # Convert character to lowercase to ignore case
            filtered_expression.append(char.lower())

    # Use two pointers to check if the string is a palindrome
    left = 0
    right = len(filtered_expression) - 1

    # Check if the string is a palindrome
    while left < right:
        if filtered_expression[left] != filtered_expression[right]:
            return False
        left  += 1
        right -= 1
    
    return True
    
