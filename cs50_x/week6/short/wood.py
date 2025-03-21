class wood:
    def __init__(self, cost):
        self.cost = cost

    def cost_evaluation(self):
        if self.cost > 10:
            return "Expensive"
        else:
            return "Cheap"

pine = wood(3)
print(pine.cost_evaluation())