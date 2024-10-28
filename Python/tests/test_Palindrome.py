import pytest
from Palindrome import is_palindrome

@pytest.fixture
def palindrome_data():
    return [
        ("A man, a plan, a canal: Panama", True),
        ("race a car", False),
        ("", True),
        (" ", True),
        ("aba", True)
    ]

def test_is_palindrome(palindrome_data):
    for expression, expected in palindrome_data:
        result = is_palindrome(expression)
        assert result == expected, f"Expected: {expected}, Got: {result}"
        