import math

first_group = int(input("Enter pupils in the first group: "))
second_group = int(input("Enter pupils in the second group: "))
third_group = int(input("Enter pupils in the third group: "))

all_pupils = first_group + second_group + third_group

tables = math.ceil(all_pupils / 2)

print(tables)