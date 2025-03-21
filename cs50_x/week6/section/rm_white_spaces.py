# Simple program to remove unnecassary beginning and trailing whitespace.

def main():
    # Gets input from standard input.
    text = input("Input: ")

    # Prints output to standard output.
    print(f"Output: {text.strip()}")

main()