# Random forest classifiers are an ensemble method that function by creating a certain number of decision trees during training, then outputs the class that is the mode of the classes

# The most simple way using RandomForestClassifier can be found at the end.

from sklearn.tree import DecisionTreeClassifier, export_graphviz
from sklearn.model_selection import train_test_split, GridSearchCV, ShuffleSplit
from sklearn.datasets import make_moons
from sklearn.metrics import accuracy_score
from sklearn.base import clone
from scipy.stats import mode

import numpy as np

# Generating a dataset
X, y = make_moons(n_samples=10000, noise=0.4, random_state=42)

# Splitting the dataset in to training and test samples
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42)

# Parameters that we would like to try out to get the best decision tree splits
params = {'max_leaf_nodes': list(range(2,100)), 'min_samples_split': [2, 3, 4]}

# Setting up our cross validation against all parameter options
# Scoring provided by the DecisionTreeClassifier method
# n_jobs=-1 to run in paralell over all avaliabel cores
grid_search_cv = GridSearchCV(DecisionTreeClassifier(random_state=1), params, n_jobs=-1, verbose=1)

# evaluating all parameter combinations on the trainig data to determin the best combination
grid_search_cv.fit(X_train, y_train)

# The best estimator detetrmined by grid_search_cv
grid_search_cv.best_estimator_

# Testing out the resulting descions tree
y_pred = grid_search_cv.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)

# 85.6% accuracy for this model
print("Decision Tree Accuracy: ", accuracy)


# Generating 1000 subsets of the training data, each with 100 different train instances
subsets = []
n_trees = 1000
rs = ShuffleSplit(n_splits=n_trees, test_size=len(X_train)-100, random_state=42)

for train_index_subset, test_index_subset in rs.split(X_train):
    X_train_subset = X_train[train_index_subset]
    y_train_subset = y_train[train_index_subset]
    subsets.append([X_train_subset, y_train_subset])

# create a forest of estimators, one for each tree
forest = [clone(grid_search_cv.best_estimator_) for _ in range(n_trees)]
total_accuracy = []

for tree, (X_train_subset, y_train_subset) in zip(forest, subsets):
    tree.fit(X_train_subset, y_train_subset)
    y_pred = tree.predict(X_test)
    total_accuracy.append(accuracy_score(y_test, y_pred))

avg_accuracy = np.mean(total_accuracy)
print(avg_accuracy)


y_pred = np.empty([n_trees, len(X_test)], dtype=np.uint8)
for tree_index, tree in enumerate(forest):
    y_pred[tree_index] = tree.predict(X_test)

#find the modal (most common) prediction from the 1000 decision trees
y_pred_majority_votes, n_votes = mode(y_pred, axis=0)

#accuracy score for the
print("Manual Forest Accuracy: ", accuracy_score(y_test, y_pred_majority_votes.reshape([-1])))

# Exports best estimator tree
export_graphviz(
        tree,
        out_file="moons_tree.dot",
        #feature_names=X.feature_names,
        #class_names=X.target_names,
        rounded=True,
        filled=True
 )


# Practical way to do random forest classification
from sklearn.ensemble import RandomForestClassifier

rnd_clf = RandomForestClassifier(n_estimators=500, max_leaf_nodes=16, n_jobs=-1)
rnd_clf.fit(X_train, y_train)

y_pred = rnd_clf.predict(X_test)
print("Random Forest Classifier Accuracy: ", accuracy_score(y_test, y_pred))
