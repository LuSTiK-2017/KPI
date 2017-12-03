n = int(input("Enter number of pins: "))
tries = int(input("Enter number of tries: "))
pins = [i for i in "I"*n]

for j in range(tries):
    f_pins = []
    for k in range(1):
        f_pins.append(int(input("Enter start place: ")))
        f_pins.append(int(input("Enter finish place: ")))
        for y in range(f_pins[0]-1, f_pins[1]):
            pins[y] = str(".")

print(''.join(str(i) for i in pins))
