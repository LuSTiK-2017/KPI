from util.utils import repeat_func, time_measure

@time_measure
@repeat_func("1")
def my_func():
    sentence = input("Enter your sentence: ")
    number_symbols = int(input("Enter number of symbol: "))

    words = sentence.split()

    # Додавання пробілу після 2-го символу до слів із кількістю символів number_symbols - 1
    for i in range(len(words)):
        if len(words[i]) == number_symbols - 1:
            new_element = words[i][:2] + " " + words[i][2:]
            words[i] = new_element 

    print("New sentence: " + " ".join(words))
