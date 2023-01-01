## gameplay algorithm based on 3x3 and adapted from : http://inventwithpython.com/chapter10.html

## we've all played 3x3 tic tac toe with another person, but what about 5x5 against a bot. The strategy is much harder! If you win, you deserve a cookie!

def displayBoard(b):
  W  = '\033[0m'  # default color
  R  = '\033[31m' # red
  G  = '\033[32m' # green
  O  = '\033[33m' # orange
  B  = '\033[34m' # blue
  P  = '\033[35m' # purple

  ms = O+'  |  '+W

  print(O+'     |     |     |     |'+W)
  print('  ' + b[0] + ms + b[1] + ms + b[2]+ms+b[3]+ms+b[4])
  print(O+'     |     |     |     |'+W)
  print(O+'-----------------------------'+W)
  print(O+'     |     |     |     |'+W)
  print('  ' + b[5] + ms + b[6] + ms + b[7]+ms+b[8]+ms+b[9])
  print(O+'     |     |     |     |'+W)
  print(O+'-----------------------------'+W)
  print(O+'     |     |     |     |'+W)
  print('  ' + b[10] + ms + b[11] + ms + b[12]+ms+b[13]+ms+b[14])
  print(O+'     |     |     |     |'+W)
  print(O+'-----------------------------'+W)
  print(O+'     |     |     |     |'+W)
  print('  ' + b[15] + ms + b[16] + ms + b[17]+ms+b[18]+ms+b[19])
  print(O+'     |     |     |     |'+W)
  print(O+'-----------------------------'+W)
  print(O+'     |     |     |     |'+W)
  print('  ' + b[20] + ms + b[21] + ms + b[22]+ms+b[23]+ms+b[24])
  print(O+'     |     |     |     |'+W)
  print('\n\n\n\n\n')

def checkDraw(b):
  return ' ' not in b

def checkWin(b, m):
  # rows
  return ((b[0] == m and b[1] == m and b[2] == m and b[3] == m and b[4] == m) or  
  (b[5] == m and b[6] == m and b[7] == m and b[8] == m  and b[9] == m) or  
  (b[10] == m and b[11] == m and b[12] == m and b[13] == m and b[14] == m) or  
  (b[15] == m and b[16] == m and b[17] == m and b[18] == m and b[19] == m) or  
  (b[20] == m and b[21] == m and b[22] == m and b[23] == m and b[24] == m) or  
  #columns
  (b[0] == m and b[5] == m and b[10] == m and b[15] == m and b[20] == m) or  
  (b[1] == m and b[6] == m and b[11] == m and b[16] == m and b[21] == m) or  
  (b[2] == m and b[7] == m and b[12] == m and b[17] == m and b[22] == m) or  
  (b[3] == m and b[8] == m and b[13] == m and b[18] == m and b[23] == m) or  
  (b[4] == m and b[9] == m and b[14] == m and b[19] == m and b[24] == m) or  
  #diagonals
  (b[0] == m and b[6] == m and b[12] == m and b[18] == m and b[24] == m) or  
  (b[4] == m and b[8] == m and b[12] == m and b[16] == m and b[20] == m))  

def getBoardCopy(b):
    # create a duplicate board to test with 
    dupeBoard = []
    for j in b:
        dupeBoard.append(j)
    return dupeBoard

def testWinMove(b, mark, i):
    # b is the board
    # mark is 0 or X
    # i is the square to check if it makes a win 
    bCopy = getBoardCopy(b)
    bCopy[i] = mark
    return checkWin(bCopy, mark)

def testForkMove(b, mark, i):
    # Does a move lead to multiple win opportunities
    bCopy = getBoardCopy(b)
    bCopy[i] = mark
    winningMoves = 0
    for j in range(0, 25):
        if testWinMove(bCopy, mark, j) and bCopy[j] == ' ':
            winningMoves += 1
    return winningMoves >= 2

def getComputerMove(b):
    # Check if the computer can make a move that leads to a direct win
    for i in range(0, 25):
        if b[i] == ' ' and testWinMove(b, 'X', i):
            return i
    # Check if the player can make a move that leads to a direct win
    for i in range(0, 25):
        if b[i] == ' ' and testWinMove(b, '0', i):
            return i
    # Check if the computer can make multiple win opportunities
    for i in range(0, 25):
        if b[i] == ' ' and testForkMove(b, 'X', i):
            return i
    #  Check if the player can make multiple win opportunities
    for i in range(0, 25):
        if b[i] == ' ' and testForkMove(b, '0', i):
            return i
    # Play a corner
    for i in [0, 4, 20, 24]:
        if b[i] == ' ':
            return i
    # Play one of the centers of the board
    for i in [6,7,8,11,12,13,16,17,18]:
        if b[i] == ' ':
            return i
    #Play one of the side spots
    for i in [1,2,3,5,10,15,9,14,19,21,22,23]:
        if b[i] == ' ':
            return i

Playing = True
while Playing:
  InGame = True
  # fill in the blank board
  board = [' '] * 25
  print('Would you like to go first or second? (1/2)')
  if input() == '1':
    playerMarker = '0'
  else:
    playerMarker = 'X'
  displayBoard(board)

  while InGame:
    if playerMarker == '0':
      print('Player go: (0-24)')
      move = int(input())
      if move>24 or move<0 or board[move] != ' ':
        print('Invalid move!')
        continue
    else:
      move = getComputerMove(board)
    board[move] = playerMarker
    if checkWin(board, playerMarker):
      InGame = False
      displayBoard(board)
      if playerMarker == '0':
        print("0's won!")
      else:
        print("X's won!")
      continue
    if checkDraw(board):
      InGame = False
      displayBoard(board)
      print('It was a draw!')
      continue
    displayBoard(board)
    if playerMarker == '0':
      playerMarker = 'X'
    else:
      playerMarker = '0'

  print('Type k to keep playing')
  inp = input()
  if inp != 'k' and inp != 'K':
    Playing = False

