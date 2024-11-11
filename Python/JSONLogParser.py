# JSON Parsing and Error Analysis in a Jenkins Pipeline
# ------------------------------------------------------
# Imagine you’re working on a vehicle diagnostics system that uses Jenkins for continuous integration. 
# The system captures test results and stores them in a list of dictionaries, each containing test metadata, 
# including the test_name, status (pass/fail), failure_reason (if failed), and duration (in seconds).
#
# Problem:
# Write a Python function analyze_pipeline_tests(tests: list) -> dict, that:
# - Identifies all tests that have failed and groups them by failure_reason.
# - Calculates the average duration for tests that passed.
# - Returns a dictionary in the following format:
#   - {
#       "failure_summary": { "<failure_reason>": ["test_name1", "test_name2", ...] },
#       "average_duration_passed_tests": <float>
#     }
#

def analyze_pipeline_tests(tests: list) -> dict:
    """
    
    """

    # Dictionary to store failure reasons and corresponding test names
    failure_summary = {}

    # Variable to store total duration of passed tests
    total_passed_duration = 0

    # Counter to keep track of the number of passed tests
    passed_test_count = 0

    # Iterate over each test in the list
    for test in tests:
        # Check if test has failed
        if test["status"] == "fail":
            reason = test["failure_reason"]
            if reason not in failure_summary:
                failure_summary[reason] = []
            # Append test name to the corresponding failure reason
            failure_summary[reason].append(test["test_name"])
        elif test["status"] == "pass":
            # For passed tests, accumulate the duration to claculate the average
            total_passed_duration += test["duration"]
            passed_test_count     += 1 
    
    # Calculate the average duration of passed tests
    if passed_test_count > 0:
        average_duration_passed_tests = total_passed_duration / passed_test_count
    else:
        average_duration_passed_tests = 0.0

    # Return the summary dictionary
    return {
        "failure_summary": failure_summary,
        "average_duration_passed_tests": average_duration_passed_tests
    }