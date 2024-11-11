# CAN Log Parser
# ------------------
# You receive vehicle CAN logs as strings, where each entry contains a timestamp, CAN ID, and data payload. 
# Your task is to parse these logs and provide a summary. Specifically, create a class CANLogParser that 
# does the following:
#   - Reads a list of log entries.
#   - Extracts the CAN ID and data payload.
#   - Tracks how many times each CAN ID appears.
#   - Tracks the last recorded data payload for each CAN ID.
#
# Here is an example log entry format
# "Timestamp: 1633043021, CAN ID: 0x18FEEE22, Data: 0xFE01A5"
#
# Implement the following methods:
#   - add_log(log_entry): Takes a single log entry, parses it, and updates the internal data structures.
#   - get_summary(): Returns a dictionary where each key is a CAN ID, and each value is a dictionary with two keys: 
#     count (number of occurrences) and last_data (last recorded data payload).

class CANLogParser:
    def __init__(self):
        # Dictonary to store CAN ID and data payload
        # Each CAN ID points to another dictionary with 'count' and 'last_data'
        self.logs = {}
    
    def add_log(self, log_entry):
        """
        Parses a single log entry, extracts CAN ID and data payload, and updates the log data

        Args:
            log_entry (str): A single log entry in the specified format
        """

        # Split the entry by comma and trim whitespace to isolate each field
        parts = log_entry.split(',')
        print(parts)

        # Initialize variables to store CAN ID and data payload
        can_id  = None
        data    = None

        # Loop over each part to find and extract CAN ID and data payload
        for part in parts:
            # Remove any leading/trailing whitespace
            part = part.strip()
            if part.startswith("CAN ID:"):
                # Extract CAN ID by splitting on the colon and trimming whitespace
                can_id = part.split("CAN ID:")[1].strip()
            elif part.startswith("Data:"):
                # Extract data payload by splitting on the colon and trimming whitespace
                data = part.split("Data:")[1].strip()
        
        # Proceed only if both CAN ID and data payload are found
        if can_id and data:
            # Check if CAN ID is already in the logs
            if can_id not in self.logs:
                # Initialize a new entry for CAN ID
                self.logs[can_id] = {
                    'count': 0,       # Track the count of occurrences 
                    'last_data': data # Track the last recorded data payload
                }
            
            # Update the entry with latest data
            self.logs[can_id]['count']     += 1
            self.logs[can_id]['last_data'] = data
        else:
            # Log entry did not match the expected format
            print(f"Warning: Log entry does not contain expected CAN ID or Data fields: {log_entry}")

    def get_summary(self):
        """
        Returns a summary of logs, including the occurrence count and last data payload for each CAN ID.
        
        Returns:
            dict: A dictionary summarizing the logs.
        """
        # Simply return the logs dictionary
        return self.logs