#AUTHOR  : Peeyush Yadav

n = int(raw_input())
array= map(int , raw_input().split())

for i in range (0,n) :
    key = array[i]
    j = i-1
    while j >= 0 and array[j] > key :
        array[j + 1] = array[j]
        j = j - 1
    array[j + 1] = key

print array
