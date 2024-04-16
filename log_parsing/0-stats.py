#!/usr/bin/python3
"""Reads stdin line by line and computes metrics
If count of lines is evenly divided by 10 and/or
keyboardinterrupt
all info will be printed"""

import sys
import datetime

# Define status codes
status_codes = [200, 301, 400, 401, 403, 404, 405, 500]

# Initialize variables
file_sizes = {}
line_count = 0

try:
    # Read stdin line by line
    for line in sys.stdin:
        # Split the line into components
        parts = line.split()

        # Check if line format matches
        if len(parts) >= 10 and parts[5].isdigit():
            ip_address = parts[0]
            status_code = int(parts[8])
            file_size = int(parts[9])

            # Update file size dictionary
            if status_code in status_codes:
                file_sizes.setdefault(status_code, 0)
                file_sizes[status_code] += file_size

            # Increment line count
            line_count += 1

            # Print statistics every 10 lines
            if line_count % 10 == 0:
                print("Total file size:", sum(file_sizes.values()))
                for code in sorted(file_sizes.keys()):
                    print(f"{code}: {file_sizes[code]}")
                print()

except KeyboardInterrupt:
    # Handle keyboard interruption
    print("\nKeyboard interruption detected. Printing current statistics:")
    print("Total file size:", sum(file_sizes.values()))
    for code in sorted(file_sizes.keys()):
        print(f"{code}: {file_sizes[code]}")
