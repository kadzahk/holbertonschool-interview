#!/usr/bin/python3
""" defines method to solve lockboxes problem """


def canUnlockAll(boxes):
    """
    determines if all boxes can be unlocked
    """
    from copy import deepcopy
    if type(boxes) is not list or len(boxes) < 1:
        return False
    for box in boxes:
        if type(box) is not list:
            return False
    copyBox = deepcopy(boxes)
    the_keys = [0]
    while len(the_keys) > 0:
        key = the_keys[0]
        the_keys = the_keys[1:]
        if type(key) is not int or key < 0:
            return False
        copyBox[key].append(-1)
        for new_key in copyBox[key]:
            if new_key is -1:
                continue
            if new_key >= len(copyBox):
                continue
            if -1 in copyBox[new_key] or new_key in the_keys:
                continue
            the_keys.append(new_key)
    for box in copyBox:
        if -1 not in box:
            return False
    return True
    