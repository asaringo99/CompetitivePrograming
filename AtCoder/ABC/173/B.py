a = int(input())
AC,WA,TLE,RE = 0
for i in range(0,a) :
  b = str(input())
  if b == "AC" :
    AC = AC + 1
  elif b == "WA" :
    WA = WA + 1
  elif b == TLE :
    TLE = TLE + 1
  else :
    RE = RE + 1

print("AC x ",AC)
print("WA x ",WA)
print("TLE x ",TLE)
print("RE x ",RE)
