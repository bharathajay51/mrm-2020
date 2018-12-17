function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
								   
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

m = size(X, 1);

J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));				 


X = [ones(m,1) X]
z2 = X * Theta1';
a2 = sigmoid(z2);
a2 = [ones(m,1) a2];
z3 = a2 * Theta2';
a3 = sigmoid(z3);
h = a3;

reg = (lambda/(2*m)) * sum( sum( (Theta1(:,2:length(Theta1))).^2 + (Theta2(:,2:length(Theta2))).^2))
J = -(1/m) * sum( sum ( y' * log(h) + (1 - y)' * log(1 - h))) + reg;

d3 = a3 - 3;
d2 = Theta2' * d3 * sigmoidGradient(z2);
t1 =  d2 * a1';
t2 =  d3 * a2';

Theta1_grad = (1/m) * (t1 + lambda * Theta1);
Theta2_grad = (1/m) * (t2 + lambda * Theta2);
 
grad = [Theta1_grad(:) ; Theta2_grad(:)];


