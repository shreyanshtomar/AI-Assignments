import numpy as np
k = 0
def printSolution(board):
    global k
    k+=1
    print(str(k)+": ")
    for i in range(8):
        for j in range(8):
            print(board[i][j], end=' ')
        print()
    print()

def isSafe(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False
    i = row
    j = col
    while j>=0 and i>=0:
        if board[i][j] == 1:
            return False
        i-=1
        j-=1
    i = row
    j = col
    while j>=0 and i<8:
        if board[i][j] == 1:
            return False
        j-=1
        i+=1
    return True

def solveQueensUtil(board, col):
    if col == 8:
        printSolution(board)
        pass
    res = False
    for i in range(8):
        if isSafe(board, i, col):
            board[i][col] = 1
            res = solveQueensUtil(board, col+1) or res
            board[i][col] = 0
    return res

def solveQueens():
    board = np.zeros((8,8))
    if not solveQueensUtil(board,0):
        pass
def main():
    solveQueens()
main()
