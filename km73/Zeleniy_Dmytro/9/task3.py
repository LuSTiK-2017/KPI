# Функція піднесення до степені за допомогою рекуррентного співвідношення
def power(a, n):
    if n > 0:
        return a*power(a, n-1)
    elif n == 0:
        return 1
    else:
        return "Error! Enter positive numbers"

a = float(input("Enter a: "))
n = int(input("Enter n: "))

print(power(a, n))
