import pytest
from ProductExceptSelf import product_except_self

@pytest.fixture
def product_data():
    return [
        ([1, 2, 3, 4], [24, 12, 8, 6]),
        ([2, 3, 4, 5], [60, 40, 30, 24]),
        ([1, 1, 1, 1], [1, 1, 1, 1]),
        ([0, 4, 0],    [0, 0, 0])
    ]

def test_product_except_self(product_data):
    for nums, expected in product_data:
        result = product_except_self(nums)
        assert result == expected, f"Expected: {expected}, Got: {result}"