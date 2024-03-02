#!/usr/bin/python3

"""
    Determine if all the boxes can be opened.

    Args:
    - boxes (list of lists): Each box is numbered sequentially from 0 to n - 1,
      and each box may contain keys to other boxes.

    Returns:
    - bool: True if all boxes can be opened, else False.

    Example:
    ```
    boxes = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes))  # Output: True

    boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    print(canUnlockAll(boxes))  # Output: True

    boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes))  # Output: False
    ```
    """

def canUnlockAll(boxes):
    if not boxes or not boxes[0]:
        return False

    n = len(boxes)
    unlocked_boxes = [False] * n
    unlocked_boxes[0] = True
    keys = set(boxes[0])

    stack = [0]
    while stack:
        current_box = stack.pop()
        for key in boxes[current_box]:
            if key < n and not unlocked_boxes[key]:
                unlocked_boxes[key] = True
                keys.update(boxes[key])
                stack.append(key)

    return all(unlocked_boxes)
