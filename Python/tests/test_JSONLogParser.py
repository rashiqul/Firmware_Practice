# Command: pytest -v -s --tb=short Python/tests/test_JSONParser.py

import pytest
from JSONLogParser import analyze_pipeline_tests

@pytest.fixture
def sample_tests_data():
    return [
        {"test_name": "test_01", "status": "pass", "failure_reason": "", "duration": 5.2},
        {"test_name": "test_02", "status": "fail", "failure_reason": "timeout", "duration": 7.0},
        {"test_name": "test_03", "status": "fail", "failure_reason": "assertion_error", "duration": 4.5},
        {"test_name": "test_04", "status": "pass", "failure_reason": "", "duration": 6.3},
        {"test_name": "test_05", "status": "fail", "failure_reason": "timeout", "duration": 5.7}
    ]

def test_JSONLogParser(sample_tests_data):
    # Act
    result = analyze_pipeline_tests(sample_tests_data)

    # Assert
    expected_result = {
        "failure_summary": {
            "timeout": ["test_02", "test_05"],
            "assertion_error": ["test_03"]
        },
        "average_duration_passed_tests": 5.75
    }
    assert result == expected_result, f"Expected {expected_result}, but got {result}"