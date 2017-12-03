m = int(input("Enter number of cells in height: "))
n = int(input("Enter number of cells in width: "))
k = int(input("Enter a number of cells you need: "))

if (((k % n) == 0) or ((k % m) == 0)) & ((m * n) >= k):
    answer = "Yes"
else:
    answer = "No"

print(answer)