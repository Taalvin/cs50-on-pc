# Simple program demonstrating looping through strings in python.
# EXTRA_NOTE: Python's for/in syntax helps you iterate through 
#             components of an "iterable" while referring to 
#             them by a convenient name.    

def main():
    text = input("Text: ")

    for c in text:
        print(c)

main()