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
    if not boxes:
        return False
    for i in range(0, len(boxes)):
        try:
            array_keys = get_all_keys(boxes[i])
            storage.update(array_keys)
            if array_keys == [] and \
                    (i + 1) not in list(storage) \
                    and i != len(boxes) - 1:
                return False
            if len(storage) == 0 and i != len(boxes) - 1:
                return False

        except Exception:
            return False
    return True
