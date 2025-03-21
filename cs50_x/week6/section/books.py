books = []

# Add three books to shelf.
for i in range(3):
    # Creating a dictionary called book.
    print(f"Book {i}")
    book = dict()

    # Gets input from standard input.
    book["title"] = input("Title: ") 
    book["author"] = input("Author: ")

    # Appends book to list(books).
    books.append(book)
    print()

# Print list of books
for book in books:
    print(f'{book["author"]} wrote {book["title"]}.')