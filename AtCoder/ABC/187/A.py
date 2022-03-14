a = list(map(str,input().split()))
A = int(a[0][0]) + int(a[0][1]) + int(a[0][2])
B = int(a[1][0]) + int(a[1][1]) + int(a[1][2])

if A > B :
  print(A)
else :
  print(B)