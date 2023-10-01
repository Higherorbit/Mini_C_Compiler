import nltk
from nltk.tree import Tree
# open text file in read mode
text_file = open("tree.txt", "r")

# read whole file to a string
data = text_file.read()

# close file
text_file.close()

print(data)
tree=Tree.fromstring(data)
print(tree.pretty_print())