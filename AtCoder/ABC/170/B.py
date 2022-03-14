a = list(map(int,input().split()))
b = list(map(int,input().split()))
T = input(a,b)

lon = abs(a[0]-b[0])
if a[1]*T - b[1]*T <= lon :
    print("Yes")
else :
    print("No")