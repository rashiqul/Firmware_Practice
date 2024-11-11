"""
Command: pytest -v -s --tb=short Python/tests/test_CANLogParser.py
"""

import pytest
from CANLogParser import CANLogParser

# Fixture to initialize a new CANLogParser instance
@pytest.fixture
def parser():
    return CANLogParser()

# Happy path test case that uses the fixture
def test_CANLogParser(parser):
    # Sample log entries to add
    log_entries = [
        "Timestamp: 1633043021, CAN ID: 0x18FEEE22, Data: 0xFE01A5",
        "Timestamp: 1633043022, CAN ID: 0x18FEEE22, Data: 0xABCD12",
        "Timestamp: 1633043023, CAN ID: 0x0CFEFA23, Data: 0xDEADBEEF",
        "Timestamp: 1633043024, CAN ID: 0x0CFEFA23, Data: 0xCAFEBABE",
        "Timestamp: 1633043025, CAN ID: 0x0CFEFA23, Data: 0xFEEDFACE"
    ]
    
    # Add log entries to parser
    for entry in log_entries:
        parser.add_log(entry)
    
    # Define the expected summary based on added logs
    expected_summary = {
        "0x18FEEE22": {"count": 2, "last_data": "0xABCD12"},
        "0x0CFEFA23": {"count": 3, "last_data": "0xFEEDFACE"}
    }
    
    # Get the actual summary from the parser
    actual_summary = parser.get_summary()
    
    # Assert that the actual summary matches the expected one
    assert actual_summary == expected_summary, "Summary does not match expected result."