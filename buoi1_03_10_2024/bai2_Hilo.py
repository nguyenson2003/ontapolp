n = int(input()) #int
b = bin(n)[2::] #string
c = int(b) #int
d = f"{c:016d}" #string
print(d[0:8])
print(d[8:16])