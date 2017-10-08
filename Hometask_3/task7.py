midnight_minutes = int(input("Enter  the minutes after midnight: "))

midnight_minutes %= 1440

hour = midnight_minutes // 60
minutes = midnight_minutes % 60

print(hour, "hour and", minutes, "minutes")






