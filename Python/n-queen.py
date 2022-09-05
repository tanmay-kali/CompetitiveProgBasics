def isSafe(row,col,board,n):
    #vertical 
    i = row-1

    while i>=0:
        if board[i][col]==1:
            return False
        i-=1
    
    #upper left diagonal
    i = row-1
    j = col-1

    while i>=0 and j>=0:
        if board[i][j]==1:
            return False
        i-=1
        j-=1
    i = row-1
    j = col+1
    while i>=0 and j<n:
        if board[i][j]==1:
            return False
        i-=1
        j+=1
    return True


def printPathsHelper(row,n,board,ans):
    if row==n:
        temp = []
        for i in range(n):
            k = ""
            for j in range(n):
                pt = board[i][j]
                if pt==0:
                    k+="."
                else:
                    k+="Q"
            temp.append(k)
        ans.append(temp)
        # print(temp)
        return ans
    for col in range(n):
        if isSafe(row,col,board,n):
            board[row][col]=1
            printPathsHelper(row+1,n,board,ans)
            board[row][col]=0
    return ans



def printPaths(n):
    board = [[0 for j in range(n)] for i in range(n)]
    ans = printPathsHelper(0,n,board,[])
    print(ans)
    pass

def main():
    """ Main entry point of the app """
    n = int(input())
    printPaths(n)


if __name__ == "__main__":
    """ This is executed when run from the command line """
    main()