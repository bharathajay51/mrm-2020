
total_iterations = 500
iterations = 0
precision = 0.0001
current_x = 3
change_in_x = 1
learning_rate = 0.01
def part_deriv(x):      #f(x) = (x+3)^2-4x
    return(2*(x + 3)-4)
while change_in_x > precision and iterations < total_iterations:
    last_x = current_x
    current_x = current_x - learning_rate * part_deriv(last_x)
    change_in_x = abs(last_x - current_x)
    iterations = iterations + 1
    print("X is : ",current_x," at iteration no. ",iterations)

