max_iters = 1000
iters = 0
precision = 0.0000001
cur_x = 3
change_in_x = 1
learning_rate = 0.01
def part_deriv(x):
    return(2*(x + 5))
while change_in_x > precision and iters < max_iters:
    prev_x = cur_x
    cur_x = cur_x - learning_rate * part_deriv(prev_x)
    change_in_x = abs(prev_x - cur_x)
    iters = iters + 1
    print("X is : ",cur_x," at iteration no. ",iters)

accuracy = (cur_x/-5) * 100;
print(accuracy)
    

