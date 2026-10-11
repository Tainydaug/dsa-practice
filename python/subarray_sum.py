print("enter non-negative numbers:")
o = []
while True:
    x = input("enter '~' to stop: ")
    if x == '~':
        break
    x = int(x)
    if x < 0:
        print("negative number, try again")
        continue
    o.append(x)

target = int(input("enter a number to sum: "))

n = len(o)
start = 0
curr_sum = 0
found = False
result = []

for end in range(n):
    curr_sum += o[end]

    while curr_sum > target and start < end:
        curr_sum -= o[start]
        start += 1

    if curr_sum == target:
        found = True
        result = o[start:end + 1]
        break

if found:
    print("the sum of subarray", result, "is equal to", target)
else:
    print("no subarray found with sum", target)
