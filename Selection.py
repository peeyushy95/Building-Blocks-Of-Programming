#AUTHOR  : Peeyush Yadav

n = int(raw_input())
array= map(int , raw_input().split())

for i in range (n-1) :
    mini = array[i]
    ind  = i
    for j in range (i+1,n):
        if array[j] < mini :
            mini = array[j]
            ind  = j 

    temp       = array[i]
    array[i]   = array[ind]
    array[ind] = temp

for i in range (n) :
    print array[i],
