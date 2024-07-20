import sys
from collections import deque


t = int(input())



for i in range(t):
    order = sys.stdin.readline().rstrip()
    n = int(input())
    num = sys.stdin.readline().rstrip()[1:-1].split(",")


    dq = deque(num)


    cnt = 0




    sign = 0

    if n == 0:
        dq = []





    for j in order:
        if j == 'R':
            cnt+=1
        if j == 'D':
            if len(dq) == 0:
                sign = 1
                print("error")
                break
            else:
                if cnt % 2 == 0:
                    dq.popleft()
                else:
                    dq.pop()


    if sign == 0:
        if(cnt % 2 == 0):
            print("[" + ",".join(dq) + "]")
        else:
            dq.reverse()
            print("[" + ",".join(dq) + "]")





        



        
            






    

    
    
    

    



