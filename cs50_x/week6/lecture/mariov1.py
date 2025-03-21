from cs50 import get_int

def main():
    # Forces user input to be positive.
    while True:
        x = get_int("Height: ")
        if x > 0:
            break

    # Prints bricks.
    for _ in range(x):
        print("#")


main()