# Hashing and Sets
# Example Question: Find the first non-repeating character in a string.
# Concepts Covered: Hash maps, set operations, efficient lookups.
# Why Relevant: Hashing can help handle unique identifiers or messages in SDV communications.

def first_non_repeating_char(s: str) -> int:
    """
    Find the first non-repeating character in a string and return its index.
    """
    # Iterate through the string and store the frequency of each character.
    char_freq = {}
    for char in s:
        if char in char_freq:
            char_freq[char] += 1
        else:
            char_freq[char] = 1
    
    # Find the first non-repeating character and return its index.
    for i, char in enumerate(s):
        if char_freq[char] == 1:
            return i
    
    return -1