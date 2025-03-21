# Showcases exception in python.

def main():
    i = get_int("Input: ")
    print(f"Output: {i}")

def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            pass

main()