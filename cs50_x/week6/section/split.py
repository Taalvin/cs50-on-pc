# Simple program demonstrating the 'split' method.
# NOTE: Strings are actually lists in python and the 'split' method
#       converts text from a list of characters to a list of words.
# EXTRA_NOTE: Python's for/in syntax helps you iterate through 
#             components of an "iterable" while referring to 
#             them by a convenient name.

def main():
    # Gets user input.
    text = input("Text: ")

    # Splits words in the text.
    words = text.split()

    # Prints text word by word.
    for word in words():
        print(word)

main()