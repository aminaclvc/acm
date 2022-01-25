""" 
Amina Colovic
Kattis Problem: Three Powers
Problem ID: threepowers
CPU Time limit: 1 sec
Memory limit: 1024 MB
Difficulty: 2.3
Language: Python
""""

def solve(n):
  begin = True
  shifts = 0

  print('{', end='')
  while n > 0:
      if (n & 1) == 1:
          if begin == True:
              print(' {:d}'.format(3**shifts), end='')
              begin = False
          else:
              print(', {:d}'.format(3**shifts), end='')
      n >>= 1
      shifts += 1
  print(' }')

while True:
  n = int(input())
  if n == 0:
      break
  solve(n-1)
