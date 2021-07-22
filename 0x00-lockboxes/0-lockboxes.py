#!/usr/bin/python3
"""  no module imported  """


def get_all_keys(node):
    """ get all keys of a node
    Args:
        boxes: list nodes
    return: list of keys
    """
    all_keys = []
    for key in node:
        all_keys.append(key)

    return all_keys


def recursion(boxes, keys, opened):
    # print('keys => {}   opened => {}'.format(keys, opened))
    if len(boxes) == len(opened):
        return True
    elif len(keys) == 0:
        return False
    elif opened.issuperset(keys):
        return False
    else:
        next_keys = set()
        for key in keys:
            if key >= len(boxes):
                continue
            opened.add(key)
            next_keys.update(boxes[key])
        return recursion(boxes, next_keys, opened)


def canUnlockAll(boxes):
    """ resolve the problem
    Args:
        boxes: list nodes
    return: bool
    """
    if not boxes:
        return False

    return recursion(boxes, set(boxes[0]), set([0]))
