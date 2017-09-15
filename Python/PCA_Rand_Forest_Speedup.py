# Reducing the dimensionality of the dataset using PCA will spead up the computations, but can also cost us some accuracy
# Below, a random forest classifier is trained first on the full dataset, then on the dimensionally reduced dataset. The accuracy for each method is then compared.  

from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import export_graphviz
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_moons
from sklearn.metrics import accuracy_score
from sklearn.decomposition import PCA

# Generating a dataset
X, y = make_moons(n_samples=10000, noise=0.4, random_state=42)

# Splitting the dataset in to training and test samples
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42)

# Fitting a random foresst classifier
rnd_clf = RandomForestClassifier(n_estimators=500, max_leaf_nodes=16, n_jobs=-1)
rnd_clf.fit(X_train, y_train)

#Making a prediction using the fitted random forest classifier
y_pred = rnd_clf.predict(X_test)
print("Random Forest Classifier Accuracy: ", accuracy_score(y_test, y_pred))

# Reducing the dataset so that ??? is 95%
PCA = PCA(n_components=.95)
X_reduced = PCA.fit_transform(X)

# Splitting the newly dimensionally reduced X and y values into train/test subsets
X_red_train, X_red_test, y_train, y_test = train_test_split(X_reduced, y, test_size=0.25, random_state=42)

# Using the random forest classifier on the dimensionally reduced feature set
rnd_clf_2 = RandomForestClassifier(n_estimators=500, max_leaf_nodes=16, n_jobs=-1)
rnd_clf_2.fit(X_red_train, y_train)

# Making a new predictions
y_red_pred = rnd_clf.predict(X_red_test)
print("Random Forest Classifier on a dimensionally reduced feature set: ", accuracy_score(y_test, y_red_pred))

## In this case, the speedup from the dimensionality reduction cost us about
## 5% accuracy
