# Python Object-Oriented Programming.

################################################
# # manually creating instance variables.
# # NOTE: Prone to typo errors.

# class Employee:
#     pass

# emp1 = Employee()
# emp1.first = "Taalvin" # NOTE: Does not need parentheses, as it is an attribute, not a method.
# emp1.last = "Coolen"

# emp2 = Employee()
# emp2.first = "Sekha"
# emp2.last = "Imrit"

# print(emp1.first)
# print(emp2.first)
################################################
# Using class as a blue-print for instances.
# NOTE: More efficient and less prone to typo errors.

class Employee:
    def __init__(self, first, last):
        self.first = first
        self.last = last

    def print_name(self):
        print(f"Full name: {self.first} {self.last}")

emp1 = Employee("Taalvin", "Coolen")
emp2 = Employee("Sekha", "Imrit")

emp1.print_name() # NOTE: Needs parentheses as it is a method.
emp2.print_name()
Employee.print_name(emp2) # NOTE: Same as above.
################################################