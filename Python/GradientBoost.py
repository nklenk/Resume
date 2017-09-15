# Gradient boosting is a boosting method that combines a bunch of weak learners into a strong single learner.
# This is accomplished by adding an estimator h to provide a better model.
# Essentially, Fn+1(X) = Fn(x) + h(x) = y where h(x) is our estimator and is detemined by h(x) = y - Fn(x)


import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeRegressor
from sklearn.metrics import mean_squared_error
from sklearn.datasets import make_moons

# Generating a dataset
X, y = make_moons(n_samples=10000, noise=0.4, random_state=42)

# Splitting the dataset in to training and test samples
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42)

# Creating an ensemble of 3 trees
tree_reg1 = DecisionTreeRegressor(max_depth=2)
tree_reg1.fit(X_train, y_train)

# Training a second DecisionTreeRegressor on the residual errors from the first predictor
y2 = y_train - tree_reg1.predict(X_train)
tree_reg2 = DecisionTreeRegressor(max_depth=2)
tree_reg2.fit(X_train, y2)

# Training a third DecisionTreeRegressor on the residuals made by the second predictor
y3 = y_train - tree_reg2.predict(X_train)
tree_reg3 = DecisionTreeRegressor(max_depth=2)
tree_reg3.fit(X_train, y3)

# Make predictions on new instances by adding up all of the predictions of all the trees
y_pred = sum(tree.predict(X_test) for tree in (tree_reg1, tree_reg2, tree_reg3))

print("MSE1: ", mean_squared_error(y_test, y_pred))

# Easy way
from sklearn.ensemble import GradientBoostingRegressor

gbrt = GradientBoostingRegressor(max_depth=2, n_estimators=3, learning_rate=1.0)
gbrt.fit(X_train, y_train)
y_pred = gbrt.predict(X_test)
print("MSE2: ", mean_squared_error(y_test, y_pred))

# Optimizing the number of trees
# Staged_predict yields the score after each iteration of boosting (num of trees)
errors = [mean_squared_error(y_test, y_pred) for y_pred in gbrt.staged_predict(X_test)]
# list location 0 -> 1 tree
best_n_estimator = np.argmin(errors) + 1

# creating a new regressor, but with the optimum number of trees
gbrt_best = GradientBoostingRegressor(max_depth=2, n_estimators=best_n_estimator, learning_rate=1.0)
gbrt_best.fit(X_train, y_train)
y_pred = gbrt_best.predict(X_test)
print("MSE3: ", mean_squared_error(y_test, y_pred))
