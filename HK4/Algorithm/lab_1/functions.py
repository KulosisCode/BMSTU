def sort_2_component(x, y):
    indices = sorted(range(len(x)), key=lambda i: x[i])
    x = [x[i] for i in indices]
    y = [y[i] for i in indices]
    return x, y


def sort_3_component(x, y, yd):
    indices = sorted(range(len(x)), key=lambda i: x[i])
    x = [x[i] for i in indices]
    y = [y[i] for i in indices]
    yd = [yd[i] for i in indices]
    return x, y, yd

# Select nodes from x, y arrays for Newton polynomial


def prepare_arrays_newton(x, y, n, x0):
    need_to_take = n + 1
    if need_to_take > len(x):
        print('ERROR: не хватает точек для построения полинома Ньютона')

    x, y = sort_2_component(x, y)

    closest_to_x0_i = (sorted(range(len(x)), key=lambda i: abs(x[i] - x0)))[0]

    from_i = closest_to_x0_i - need_to_take // 2
    if from_i < 0:
        from_i = 0
    to_i = from_i + need_to_take
    if to_i > len(x):
        to_i = len(x)
        from_i = to_i - need_to_take

    x_new = x[from_i: to_i]
    y_new = y[from_i: to_i]
    return x_new, y_new

# Select nodes from x, y arrays for Hermite polynomial


def prepare_arrays_hermite(x, y, yd, n, x0):

    need_to_take = (n // 2) + 1
    if need_to_take > len(x):
        print('ERROR: не хватает точек для построения полинома Эрмита')

    x, y, yd = sort_3_component(x, y, yd)

    closest_to_x0_i = (sorted(range(len(x)), key=lambda i: abs(x[i] - x0)))[0]

    from_i = closest_to_x0_i - need_to_take // 2
    if from_i < 0:
        from_i = 0
    to_i = from_i + need_to_take
    if to_i > len(x):
        to_i = len(x)
        from_i = to_i - need_to_take

    x_new = []
    y_new = []
    yd_new = []
    for i in range(from_i, to_i):
        x_new.append(x[i])
        x_new.append(x[i])
        y_new.append(y[i])
        y_new.append(y[i])
        yd_new.append(yd[i])
    return x_new, y_new, yd_new

# Search for coefficients for Newton's interpolation polynomial of n-th degree


def find_coeffs_newton(x, y, n):
    coeffs = [y[0]]

    for step in range(n):

        for i in range(n - step):

            y[i] = (y[i + 1] - y[i])/(x[i + step + 1] - x[i])
        coeffs.append(y[0])
    return coeffs

# Search for coefficients for Hermite's interpolation polynomial of n-th degree


def find_coeffs_hermite(x, y, yd, n):
    coeffs = [y[0]]

    for step in range(n):

        for i in range(n - step):

            if (step == 0) and (i % 2 == 0):
                y[i] = yd[i // 2]
            else:
                y[i] = (y[i + 1] - y[i])/(x[i + step + 1] - x[i])
        coeffs.append(y[0])
    return coeffs

# Calculation of a polynomial of degree n with coefficients by array x at point x0


def count_polynom(x, coeffs, n, x0):
    sum_all = 0

    for stage in range(n + 1):
        sum_step = coeffs[stage]
        for i in range(stage):
            sum_step *= (x0 - x[i])

        sum_all += sum_step
    return sum_all

# The value of the Newton polynomial at the point x0


def approximate_newton(x, y, n, x0):
    x_newton, y_newton = prepare_arrays_newton(x, y, n, x0)
    coeffs = find_coeffs_newton(x_newton, y_newton, n)
    return count_polynom(x_newton, coeffs, n, x0)

# Finding the root of a function using reverse interpolation
# using the Newton polynomial.


def find_root_back_interp(x, y, n):
    return approximate_newton(y, x, n, 0)


# Value of the Hermite polynomial at the point x0
def approximate_hermite(x, y, yd, n, x0):
    x_hermite, y_hermite, yd_hermite = prepare_arrays_hermite(x, y, yd, n, x0)
    coeffs = find_coeffs_hermite(x_hermite, y_hermite, yd_hermite, n)
    return count_polynom(x_hermite, coeffs, n, x0)


def main():
    print('Test on a straight line')
    print('Newton: Expected 2.0, got',
          approximate_newton([1., 3.], [1., 3.], 1, 2))
    print('Ermit: Expected 2.0, got', approximate_hermite(
        [1., 3.], [1., 3.], [1, 1], 3, 2))
    print('Root: Expected 0.0, got',
          find_root_back_interp([-1, 1], [-1, 1], 1))
    print('Test Newton on example from lection')
    x = [0, 0.25, 0.5, 0.75, 1]
    y = [1, 0.924, 0.707, 0.383, 0.000]
    n = 4
    x0 = 0.6
    print('Expected 0.589, got', approximate_newton(x, y, n, x0))


if __name__ == "__main__":
    main()
