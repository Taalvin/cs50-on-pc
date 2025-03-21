# Simple program that showcases how to create a class in python.

class Student:
    def __init__(self, name, uni):  
        self.name = name
        self.uni = uni

    def changeID(self, new_uni):
        self.uni = new_uni

    def print(self):
        print(f"{self.name} goes to {self.uni}")

student = Student("Nemisha", "DRSSS")
student.print()
student.changeID("UOM")
student.print()