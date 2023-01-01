from numpy import arange
import matplotlib.pyplot as plt


class Point:
    def __init__(self, x=0, y=0, weight=1):
        self.x = x
        self.y = y
        self.weight = weight

    def __str__(self):
        return f"|{self.x:^10.2f} | {self.y:^10.2f} | {self.weight:^10.2f} |"


def print_table(table):
    print(" _____________________________________")
    print("|      X    |      Y     |   weight   |")
    print("|-------------------------------------|")
    for i in range(len(table)):
        print(table[i])
    print("|_____________________________________|")


def read_from_file(file_input):
    dots = list()
    with open(file_input, "r") as f:
        line = f.readline()
        while line:
            x, y, weight = map(float, line.split())
            dots.append(Point(x, y, weight))
            line = f.readline()
    return dots

#calculate the right part
def append_right_side(matrix, dots):
    for i in range(len(matrix)):
        res = 0
        for j in range(len(dots)):
            res += dots[j].weight * dots[j].y * (dots[j].x ** i)
        matrix[i].append(res)


def get_coefficient(dots, degree):
    coefficient = 0
    for i in range(len(dots)):
        coefficient += dots[i].weight * (dots[i].x ** degree)
    return coefficient


def find_slau_matrix(dots, degree):
    # get the left part
    matrix = [[get_coefficient(dots, j + i) for i in range(degree + 1)]
              for j in range(degree + 1)]
    # get the right part
    append_right_side(matrix, dots)
    return matrix

#СЛАУ решение
def get_polynomial_coefficients(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if i == j:
                continue
            multiplication = matrix[j][i] / matrix[i][i]
            for k in range(0, len(matrix) + 1):
                matrix[j][k] -= multiplication * matrix[i][k]

    for i in range(len(matrix)):
        multiplication = matrix[i][i]
        for j in range(len(matrix[i])):
            matrix[i][j] /= multiplication

    return [matrix[i][-1] for i in range(len(matrix))]

#Create data x, y for function founded
def add_plot(coeffs, label, start, end):
    my_x = list()
    my_y = list()
    step = (end - start) / 1000
    for x in arange(start, end + step, step):
        my_x.append(x)
        y = 0
        for i in range(len(coeffs)):
            y += coeffs[i] * x ** i
        my_y.append(y)

    plt.plot(my_x, my_y, label=label)


def add_table(table, label):
    table_x = [table[i].x for i in range(len(table))]
    table_y = [table[i].y for i in range(len(table))]

    plt.plot(table_x, table_y, 'o', label=label)


def draw_result():
    plt.legend()

    plt.xlabel('X') 
    plt.ylabel('Y')

    plt.grid()
    plt.show()


def d2():

    filename = 'data_2d.txt'
    degrees = list(map(int, input("Введите степени полиномов: ").split()))

    points = read_from_file(filename)
    add_table(points, "Table")

    print_table(points)

    for j in range(len(degrees)):
        slau_matrix = find_slau_matrix(points, degrees[j])
        print("n = {}".format(degrees[j]))
        coeffs = get_polynomial_coefficients(slau_matrix)
        print("Найденные коэффиценты полинома")
        print(coeffs)
        add_plot(coeffs, f"n = {degrees[j]}",
                 points[0].x, points[-1].x)

    draw_result()
