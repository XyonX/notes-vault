if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    scores = set(arr)            # Remove duplicates
    list1 = list(scores)         # Convert to list
    list1.sort()                 # Sort ascending
    print(list1[-2])             # Second highest = second last element