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


def canUnlockAll(boxes):
    """ resolve the problem
    Args:
        boxes: list nodes
    return: bool
    """
    storage = set()

    for i in range(0, len(boxes)):
        try:
            array_keys = get_all_keys(boxes[i])
            if array_keys == [] and max(storage) <= i and i != len(boxes) - 1:
                return False
            storage.update(array_keys)
        except Exception as error:
            return False
    return True
