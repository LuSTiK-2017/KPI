x = float(input("Enter variable X: "))

if x > 0:
    sign = 1
elif x < 0:
    sign = -1
else:
    sign = 0

print("sign(x) =", sign)