#how ew can make string using iteraive for loop
if __name__ == '__main__':
    n = int(input())
    res=""
    for i in range(1,n+1):
        res+=str(i)
    print(res)
# a clean way of doing the same
# print("".join(str(i) for i in range(1, n+1)))
#or
if __name__ == '__main__':
    n = int(input())
    res = "".join(str(i) for i in range(1, n + 1))
    print(res)