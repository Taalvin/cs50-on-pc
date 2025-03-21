class Student:
    def __init__(self, name, grade, maths, science, english):
        self.name = name
        self.grade = grade
        self.maths = maths
        self.science = science
        self.english = english
        self.avr_scr = (maths + science + english) / 3

std1 = Student("Taalvin", 6, 25, 25, 25)

print(std1.avr_scr)
