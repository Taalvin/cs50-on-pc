# Simple program that showcases if/in features of python-Filters
# words containing the letter n from inputted text.

def main():
    # Gets input from standard input.
    text = input("Text: ")

    # Prints words from text that contain the letter n.
    print()
    print("Words with the letter n:")
    for word in text.split():
        if "n" in word or "N" in word:
            print(word)

main()