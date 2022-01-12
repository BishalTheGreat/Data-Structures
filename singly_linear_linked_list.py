#! /bin/python3
# This is singly linear linked list in Python
# First make Node class, It is used to store node data and connection to next node
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __str__(self):
        return "This is Node."

# Make linked list class
class SLLL:
    def __init__(self):
        self.first = None

    # Insertion into Linked list at specific position
    def insert(self, position, node):
        p = self.first
        while(position > 2):
            p = p.next
            position -= 1

        node.next = p.next
        p.next = node

    # Deletion at specific position
    def delete(self, position):
        p = self.first
        while position > 2:
            p = p.next
            position -= 1

        node = p.next
        p.next = p.next.next
        return node

    # Disply Linked list
    def display(self):
        p = self.first
        while True:
            print(p.data)
            p = p.next
            if p.next == None:
                print(p.data)
                break

    def __str__(self):
        return "This is Singly Linear Linked List."

# Start making and linking lists
# Create Nodes
list1 = Node("First Node")
list2 = Node("Second Node")
list3 = Node("Third Node")
list4 = Node("Fourth Node")
list5 = Node("Fifth Node")

# Here, linked_list is the object of SLLL. It must point first list to start linking
linked_list = SLLL()
linked_list.first = list1

# Linking all nodes
list1.next = list2
list2.next = list3
list3.next = list4
list4.next = list5

temp = Node("Inserted node")

print("Before Insertion:")
linked_list.display()
print("\nAfter Insertion:")
linked_list.insert(4, temp)
linked_list.display()

node = linked_list.delete(2)
print("Deleted Node: {}".format(node.data))

print("\nAfter deletion:")
linked_list.display()
