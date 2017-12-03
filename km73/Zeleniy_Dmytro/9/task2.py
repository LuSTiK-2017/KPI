# Функція розрахунку числа а в стeпені n
def power(a, n):
    if n < 0:
        result = "Error! Enter positive numbers"
    else:
        result = 1
        for i in range(n):
            result *= a
    return result

a = float(input("Enter a: "))
n = int(input("Enter n: "))

print(power(a, n))
