def print_num(n):
    if(n >= 2):
        print_num(n-1)
    for i in range(1,10**n):
        print(i)

print_num(2)
