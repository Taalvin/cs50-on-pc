# Simple program that makes ascii art of bricks.

def main():
    # Gets input from standard input.
    x = int(input("x: "))
    y = int(input("y: "))

    # Prints output to standard output.
    for i in range(y):
        print("#" * x)

main() 