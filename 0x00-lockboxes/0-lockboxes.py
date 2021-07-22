
boxes = [[1], [2], [3], [4], []]


def get_all_keys(node):
    all_keys = []
    for key in node:
        all_keys.append(key)

    return all_keys


def canUnlockAll(boxes):
    storage = set()

    for i in range(0, len(boxes)):
        try:
            array_keys = get_all_keys(boxes[i])
            if array_keys == [] and max(storage) <= i and i != len(boxes) - 1:
                return False
            storage.update(array_keys)
        except Exception as error:
            print("error", error)
    return True
