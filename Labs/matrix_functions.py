import random

def create_random_matrix(n, m):
    matrix = [[0] * m for i in range(n)]
    for j in range(n):
        for k in range(m):
            matrix[j][k] = str(random.randint(-100, 100))
    return matrix

def create_user_matrix(n, m):
    matrix = [[0] * m for i in range(n)]
    for j in range(n):
        for k in range(m):
            matrix[j][k] = input("Input element[" + str(j) + "][" + str(k) +"] : ")
    return matrix

