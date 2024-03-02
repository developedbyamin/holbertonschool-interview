#!/usr/bin/python3
def canUnlockAll(boxes):
    if not boxes or not boxes[0]:
        return False

    n = len(boxes)
    unlocked_boxes = set([0])
    keys_to_process = set([0])  # Initialize with the first box

    while keys_to_process:
        current_box = keys_to_process.pop()

        for key in boxes[current_box]:
            if key < n and key not in unlocked_boxes:
                unlocked_boxes.add(key)
                keys_to_process.add(key)

    return len(unlocked_boxes) == n
