from x_y import d2
from x_y_z import d3


def menu():
    print("1. Двумерная апроксимация")
    print("2. Трёхмерная апроксимация")
    print("0. Выход")
    print("Выбор: ", end = "")
    cur = int(input())
    return cur


def main():
    command = menu()
    while command != 0:
        if command == 1:
            d2()
        elif command == 2:
            d3()
        else:
            print("Неверный ввод")
        command = menu()

main()
