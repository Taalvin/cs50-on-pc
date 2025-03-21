# Compares two numbers.

def main():
    # Gets input from standard input.
    x = int(input("x: "))
    y = int(input("y: "))

    # Prints output to standard output.
    if x > y:
        print("x is greater than y.")
    elif x < y:
        print("y is greater than x.")
    else:
        print("x is equal to y.")

main()