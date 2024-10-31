import pytest
from BinarySearch import binary_search

@pytest.fixture
def binary_search_data():
    return [
        ([1, 2, 3, 4, 5, 6], 4, 3),
        ([10, 20, 30, 40, 50], 25, -1),
        ([5], 5, 0),
        ([1, 3, 5, 7, 9], 3, 1)
    ]

def test_binary_search(binary_search_data):
    for arr, target, expected in binary_search_data:
        assert binary_search(arr, target) == expected