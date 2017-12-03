year = int(input("Enter any year: "))

if year % 4 == 0 and not year % 100 == 0 or year % 400 == 0:
    type_of_year = "LEAP"
else:
    type_of_year = "COMMON"
    
print(type_of_year)