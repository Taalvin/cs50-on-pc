# Simple terms and conditions program.

def main():
    # Gets input from standard input.
    answers = ["y", "n", "yes", "no"]
    while True:
        answer = input("Do you agree?[y/n] ").lower()
        if answer in answers:
            break

    # Prints output to standard output.
    if answer in ["yes", "y"]:
        print("User has agreed.")
    if answer in ["no", "n"]:
        print("User has not agreed.")

main()