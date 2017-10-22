while True:
    numbers = [] # Створюємо порожній масив в який будемо поміщати довільні числа числа

    N = int(input("Enter amount of elements: ")) # Кількість елементів в масиві

    for i in range(N):
        number = float(input("Element: "))
        numbers.append(number)
        if number < 0:
            numbers.append(number**2)

    print(numbers)

    to_exit = input("Enter 0 to exit or any other character to continue: ")
    if to_exit == "0":
        break
