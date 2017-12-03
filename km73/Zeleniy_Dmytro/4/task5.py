a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
c = int(input("Enter third number: "))

if a == b == c:
    quantity = 3
elif a == b or a == c or b == c:
    quantity = 2
else:
    quantity = 0

print("Quantity of equal numbers: ", quantity)
    