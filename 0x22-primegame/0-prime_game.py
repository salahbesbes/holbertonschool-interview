""" Prime Game """


def isWinner(x, nums):
    """ Returns name of the player that won the most rounds: Maria or Bill """

    if x < 1 or not nums:
        return None

    n = max(nums)
    player = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(n**0.5) + 1):
        if not player[i]:
            continue
        for j in range(i*i, n + 1, i):
            player[j] = False

    player[0] = player[1] = False
    c = 0
    for i in range(len(player)):
        if player[i]:
            c += 1
        player[i] = c

    result = 0
    for n in nums:
        result += player[n] % 2 == 1
    if result * 2 == len(nums):
        return None
    if result * 2 > len(nums):
        return "Maria"
    return "Ben"
