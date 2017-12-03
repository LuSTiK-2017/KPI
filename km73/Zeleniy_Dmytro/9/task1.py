from math import sqrt


# Розрахунок відстані між точками
def distance(x1, y1, x2, y2):
    dist = sqrt((x2-x1)**2 + (y2-y1)**2)
    return dist

x1 = int(input("x1: "))
y1 = int(input("y1: "))
x2 = int(input("x2: "))
y2 = int(input("y2: "))

print(distance(x1, y1, x2, y2))
