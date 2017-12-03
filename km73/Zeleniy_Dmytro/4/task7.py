start_row  = int(input("Enter start row: "))
start_column  = int(input("Enter start column: "))

finish_row = int(input("Enter finish row: "))
finish_column = int(input("Enter finish column: "))

if start_row > 0 and start_row <= 8 and start_column > 0 and start_column <= 8 and finish_row > 0 and finish_row <= 8 and finish_column > 0 and finish_column <= 8:
    if (start_column + start_row) % 2 == (finish_column + finish_row) % 2 :
        answer = "Yes"
    else:
        answer = "No"
else:
    answer = "NOT CORRET DATA!"

print(answer)