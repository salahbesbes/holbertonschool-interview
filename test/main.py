# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
if __name__ == "__main__":

    def solution(A, B):
        A.sort()
        B.sort()
        set(B)
        i = 0
        for a in A:
            if i < len(B) - 1 and B[i] < a:
                i += 1
            if a == B[i]:
                return a
        return -1


print(solution([1, 3, 3, 1],  [4, 2, 5, 3, 2]))
