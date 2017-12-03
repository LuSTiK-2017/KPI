import matrix_functions
from util.utils import repeat_func

print("Лабораторна робота №5. Робота над матрицями. Зелений Д.Г. КМ-73.")

@repeat_func("1")
def main():

    n = int(input("Enter number of row: "))
    m = int(input("Enter number of column: "))

    print("Input 1 - Input random elements \nInput 2 - Input elements one by one")
    variant = input()

    if variant == "1":
        matrix = matrix_functions.create_random_matrix(n, m)
    elif variant == "2":
        matrix = matrix_functions.create_user_matrix(n, m)
    else:
        print("Error!!!")
    
    print("Start matrix: ")
    for i in range(n):
        print(" ".join(matrix[i]))
    
    l = int(input(("L row: "))) - 1
    line = list(matrix[l])

    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] = str(int(matrix[i][j]) + int(line[j]))
   
    print("Result: ")
    for i in range(len(matrix)):
        print(" ".join(matrix[i]))

main()