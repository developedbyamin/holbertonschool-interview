 **# canUnlockAll README**

**This repository contains Python code for solving the "lockboxes" problem.**

**## Problem Description**

Given a list of boxes, where each box contains keys that can unlock other boxes, determine whether it's possible to unlock all boxes starting with the first box.

**## Usage**

1. **Save the code as `canUnlockAll.py`.**
2. **Run the code from a terminal:**

   ```bash
   python3 canUnlockAll.py
   ```

**## Input**

The code expects a list of lists as input, representing the boxes and their keys. Each nested list represents a box, and the elements within that list represent the keys contained in that box.

**## Example**

```python
boxes = [[1], [2], [3], [4], [5], [6], [7], [0]]
result = canUnlockAll(boxes)  # True
```

**## Function Explanation**

- **`canUnlockAll(boxes)`:**
    - Checks for empty input and returns `False` if necessary.
    - Initializes variables to track unlocked boxes and keys to process.
    - Iterates through keys, unlocking boxes and adding accessible keys to the processing set.
    - Returns `True` if all boxes are unlocked, `False` otherwise.

**## Additional Information**

- The code prioritizes clarity and readability.
- It uses sets for efficient membership checks and key tracking.
- The algorithm explores reachable boxes using a depth-first search approach.

**## License**

© HOLBERTON 2024

**## Contributing**

We welcome contributions! Please feel free to suggest improvements or create pull requests.
