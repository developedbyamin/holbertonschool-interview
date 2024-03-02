#!/usr/bin/python3
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
