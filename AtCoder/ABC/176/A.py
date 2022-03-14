a = str(input())
ans = 0 
for i in a :
  ans = ans + int(i)
if ans % 9 == 0 :
  print("Yes")
else :
  print("No")