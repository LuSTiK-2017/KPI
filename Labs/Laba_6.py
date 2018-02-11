from util.utils import repeat_func

print('Лабораторна робота №6. СТРУКТУРИ ДАНИХ: СПИСКИ, КОРТЕЖІ, МНОЖИНИ.'
        'Зелений Д.Г. КМ-73\n\n'
        'Варіант 11\n'
        'Створити список, елементами якого будуть слова. Необхідно:\n'
        '- порахувати, скільки раз кожен символ зустрічається в списку;\n'
        '- створити новий список, елументи якого будуть складені в список, що складаються\n'
        ' з двух елементів: символ і кількість його повторень в даному списку. Наприклад, [‘s’,10];\n'
        '- упорядкувати новий список або по символу або по числу;\n'
        '- типом даних dict в цьому завданні не користуватись.\n')


def list_count_symbol(list_words):
    "Create a new list with symbols and numbers of symbols"
    def count_symbol(list_words, symbol):
        "Number of symbol in words"
        count = 0
        for i in range(len(list_words)):
            for j in range(len(list_words[i])):
                if list_words[i][j] == symbol:
                    count += 1
        return count

    list_symbol_count = []
    list_symbols = []

    for i in range(len(list_words)):
        for j in range(len(list_words[i])):
            if list_symbols.count(list_words[i][j]) == 0:
                list_symbols.append(list_words[i][j])

    for k in range(len(list_symbols)):
        list_symbol_count.append([list_symbols[k], count_symbol(list_words, list_symbols[k])])

    return list_symbol_count


def sort_list_symbol(list_symbol_count, idx):
    "This function sort list by symbols"
    for i in range(len(list_symbol_count)):
        for j in range(len(list_symbol_count)):
            if list_symbol_count[i][idx] < list_symbol_count[j][idx]:
                element = list_symbol_count[i]
                list_symbol_count[i] = list_symbol_count[j]
                list_symbol_count[j] = element
    return list_symbol_count


@repeat_func("1")
def main():
    n = int(input("Enter number of words you want to input: "))
    list_words = [input("Input word: ") for word in range(n)]

    result = list_count_symbol(list_words)

    variant = input("1 - sort list by symbol\n2 - sort list by number\n")
    if variant == "1":
        sort_result = sort_list_symbol(result, 0)
    elif variant == "2":
        sort_result = sort_list_symbol(result, 1)
    print(sort_result)

main()
