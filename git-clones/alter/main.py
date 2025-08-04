import sympy as sp
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

def parse_expression(expression):
    return sp.sympify(expression)

def solve_equation(equation_str):
    equation = sp.sympify(equation_str)
    x = sp.symbols('x')
    solutions = sp.solve(equation, x)
    return equation, solutions

def solve_inequality(inequality_str):
    inequality = sp.sympify(inequality_str)
    x = sp.symbols('x')
    solutions = sp.solve_univariate_inequality(inequality, x)
    return inequality, solutions

def differentiate(expression, variable):
    return sp.diff(expression, variable)

def trapezoidal_rule(f, a, b, n=1000):
    x = np.linspace(a, b, n)
    y = f(x)
    h = (b - a) / (n - 1)
    return (h / 2) * (y[0] + 2 * y[1:-1].sum() + y[-1])

def evaluate_integral(expression, variable, lower_limit=None, upper_limit=None):
    expr = sp.sympify(expression)
    if lower_limit is not None and upper_limit is not None:
        integral = sp.integrate(expr, (variable, lower_limit, upper_limit))
        func = sp.lambdify(variable, expr, "numpy")
        numeric_integral = trapezoidal_rule(func, lower_limit, upper_limit)
        return expr, integral, numeric_integral
    else:
        integral = sp.integrate(expr, variable)
        return expr, integral

def solve_ode(equation_str, dependent_var_str, independent_var_str):
    dependent_var = sp.Function(dependent_var_str)
    independent_var = sp.symbols(independent_var_str)
    equation = sp.sympify(equation_str)
    solution = sp.dsolve(equation, dependent_var(independent_var))
    return equation, solution

def plot_function_and_integral(expression, lower_limit, upper_limit):
    x = np.linspace(lower_limit, upper_limit, 400)
    f = sp.lambdify('x', expression, "numpy")
    y = f(x)
    
    plt.plot(x, y, label=f'Function: {expression}')
    # Fill area under the curve
    plt.fill_between(x, y, alpha=0.3)
    plt.title(f'Graph of {expression}')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.legend()
    plt.grid(True)
    plt.show()

def curl(vector_field, variables):
    return sp.Matrix([
        sp.diff(vector_field[2], variables[1]) - sp.diff(vector_field[1], variables[2]),
        sp.diff(vector_field[0], variables[2]) - sp.diff(vector_field[2], variables[0]),
        sp.diff(vector_field[1], variables[0]) - sp.diff(vector_field[0], variables[1])
    ])

def matrix_operations(matrix_str, operation):
    matrix = sp.Matrix(sp.sympify(matrix_str))
    if operation == 'inverse':
        return matrix.inv()
    elif operation == 'eigenvalues':
        return matrix.eigenvals()
    elif operation == 'eigenvectors':
        return matrix.eigenvects()
    else:
        return "Invalid operation"

if __name__ == "__main__":
    print("Welcome to the sympy solver!")
    print("We are here to solve your complex programs :))")
    options = {
        '1': "Solve an equation",
        '2': "Evaluate an integral",
        '3': "Differentiate a function",
        '4': "Solve an inequality",
        '5': "Compute curl of a vector field", 
        '6': "Perform matrix operations",
        '7': "Solve an ODE", 
    }

    for key, value in options.items():
        print(f"{key}: {value}")

    choice = input("Choose an option: ")

    if choice == '1':
        equation_str = input("Enter an algebraic equation (e.g., x**2 + 3*x + 2): ")
        equation, solutions = solve_equation(equation_str)
        print(f"Equation: {equation}")
        print(f"Solutions: x = {solutions}")
    elif choice == '2':
        expression = input("Enter an integral expression in terms of x (e.g., x**2): ")
        lower_limit = input("Enter the lower limit of integration (or leave blank for indefinite integral): ")
        upper_limit = input("Enter the upper limit of integration (or leave blank for indefinite integral): ")
        lower_limit = float(lower_limit) if lower_limit else None
        upper_limit = float(upper_limit) if upper_limit else None
        if lower_limit is not None and upper_limit is not None:
            expr, integral, numeric_integral = evaluate_integral(expression, sp.symbols('x'), lower_limit, upper_limit)
            print(f"Integral of {expr} from {lower_limit} to {upper_limit} is {integral} (approx: {numeric_integral})")
            plot_function_and_integral(expr, lower_limit, upper_limit)
        else:
            expr, integral = evaluate_integral(expression, sp.symbols('x'))
            print(f"Indefinite integral of {expr} is {integral}")
    elif choice == '3':
        expression = input("Enter an expression to differentiate (e.g., x**2 + 3*x + 2): ")
        variable = input("Enter the variable to differentiate with respect to (e.g., x): ")
        derivative = differentiate(expression, sp.symbols(variable))
        print(f"The derivative of {expression} with respect to {variable} is {derivative}")
    elif choice == '4':
        inequality_str = input("Enter an inequality (e.g., x**2 > 4): ")
        inequality, solutions = solve_inequality(inequality_str)
        print(f"Inequality: {inequality}")
        print(f"Solutions: {solutions}")
    elif choice == '5':
        num_components = int(input("Enter the number of components in the vector field: "))
        vector_field = []
        for i in range(num_components):
            component = input(f"Enter component {i+1} (e.g., x*y): ")
            vector_field.append(parse_expression(component))
        variables = input("Enter the variables (e.g., x y z): ").split()
        variables = [sp.symbols(var) for var in variables]
        crl = curl(vector_field, variables)
        print(f"The curl of the vector field is {crl}")
    elif choice == '6':
        matrix_str = input("Enter the matrix (e.g., [[1, 2], [3, 4]]): ")
        operation = input("Enter the matrix operation (inverse, eigenvalues, eigenvectors): ")
        result = matrix_operations(matrix_str, operation)
        print(f"The result of the {operation} is: {result}")
    elif choice == '7':
        equation_str = input("Enter the ODE (e.g., Eq(Derivative(f(x), x, x) + f(x), 0)): ")
        dependent_var_str = input("Enter the dependent variable (e.g., f): ")
        independent_var_str = input("Enter the independent variable (e.g., x): ")
        equation, solution = solve_ode(equation_str, dependent_var_str, independent_var_str)
        print(f"The solution to the ODE {equation} is {solution}")
    else:
        print("Invalid choice")