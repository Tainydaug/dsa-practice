

arr = [12, 34, 56, 78, 90, 23, 45, 67]
key = 45
for i in range(len(arr)):
    if arr[i] == key:
        print("key found at index:", i)
        break
else:
    print("key not found")
    

    