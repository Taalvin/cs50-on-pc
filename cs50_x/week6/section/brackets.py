# Simple program that showcases brackets in python.
# NOTE: Provides range of elements from list.

def main():
    # Gets input from standard input.
    text = input("Input: ")

    # Prints text(list) but without the first 3 words.
    # NOTE: 3 < text (range)
    print()
    print("Output: ", end="")
    word = text.split()[3:]
    print(word)

    # Prints text(list) but only the 2nd word to the 4th word.
    # NOTE: 2 < text < 4 (range)
    print()
    print("Output: ", end="")
    word = text.split()[2:4]
    print(word)

main()