import csv

books = []

# Add books to shelf by reading from books.csv
with open("books.csv") as file:
    reader = csv.DictReader(file)
    for book in reader:
        books.append(book)

# Print books
for book in books:
    print(f'{book["author"]} wrote {book["title"]}.')