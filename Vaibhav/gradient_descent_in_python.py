max_iterations = 1000
iterations = 0
precision = 0.0000001
current_x = 3
change_in_x = 1
learning_rate = 0.01
def part_deriv(x):
    return(2*(x + 5))
while change_in_x > precision and iterations < max_iterions:
    previous_x = current_x
    current_x = current_x - learning_rate * part_deriv(previous_x)
    change_in_x = abs(previous_x - current_x)
    iterations = iterations + 1
    print("X is : ",current_x," at iteration no. ",iteratons)

    

