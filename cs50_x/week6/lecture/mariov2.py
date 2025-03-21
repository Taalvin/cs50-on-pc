from cs50 import get_int

def main():
    # Gets user input.
    r = pos_get_int("Row: ")
    h = pos_get_int("Heigth: ")

    # Prints output.
    for _ in range(h):   
        print("#" * r)


# Forces range to be a positive integer.
def pos_get_int(prompt):
    while True:
        x = get_int(prompt)
        if x > 0:
            return x


main()