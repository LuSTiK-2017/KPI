first_number = int(input("Enter first number: "))
second_number = int(input("Enter second number: "))
third_number = int(input("Enter third number: "))

if first_number <= second_number and first_number <= third_number:
    min_number = first_number
elif second_number <= first_number and second_number <= third_number:
    min_number = second_number
else:
    min_number = third_number

print(min_number)