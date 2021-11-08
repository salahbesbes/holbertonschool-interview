def matrix(n, m, li):
 
    # Counter Variable
    ctr = 0
    while(ctr < 2 * n-1):
        print(" "*abs(n-ctr-1), end ="")
        lst = []
 
        # Iterate [0, m]
        for i in range(m):
 
                # Iterate [0, n]
            for j in range(n):
 
                # Diagonal Elements
                # Condition
                if i + j == ctr:
 
                    # Appending the
                    # Diagonal Elements
                    lst.append(li[i][j])
 
        # Printing reversed Diagonal
        # Elements
        lst.reverse()
        print(*lst)
        ctr += 1
 