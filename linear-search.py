def linear_search(arr, x):
    n = len(arr)
    for i in range (0, n):
        if (arr[i] == x):
            print("The element is found at the position ",i)
    print("The element is not present in the array")