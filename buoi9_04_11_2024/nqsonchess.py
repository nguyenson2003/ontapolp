mod=1000000007
def test():
    n = int(input())
    if(n==1):
        print(0)
        return
    if n==2:
        print(4)
        return
    if n==3:
        print(36)
        return
    cell = n*n
    allRes = cell*(cell-1)*(cell-2)//6
    minus = 4*2*(cell-3) + 8*3*(cell-4) + (n-4)*4*4*(cell-5) + 4*4*(cell-5) + (n-4)*4*6*(cell-7) + (n-4)*(n-4)*8*(cell-9)
    minus//=2
    print((allRes-minus)%mod)

test()