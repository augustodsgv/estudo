''' avl tree'''
def avl_tree(root):
    ''' avl tree'''
    if root is None:
        return 0
    return root.height

''' remove from avl tree'''
def remove_from_avl(root, value):
    ''' remove from avl tree'''
    if root is None:
        return None
    if value < root.value:
        root.left = remove_from_avl(root.left, value)
    elif value > root.value:
        root.right = remove_from_avl(root.right, value)
    else:
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left
        temp = root.right
        while temp.left is not None:
            temp = temp.left
        root.value = temp.value
        root.right = remove_from_avl(root.right, temp.value)
    root.height = max(avl_tree(root.left), avl_tree(root.right)) + 1
    return root

''' insert in avl tree'''
def insert_in_avl(root, value):
    ''' insert in avl tree'''
    if root is None:
        return Node(value)
    if value < root.value:
        root.left = insert_in_avl(root.left, value)
    elif value > root.value:
        root.right = insert_in_avl(root.right, value)
    root.height = max(avl_tree(root.left), avl_tree(root.right)) + 1
    return root

''' avl tree node'''
class Node:
    ''' avl tree node'''
    def __init__(self, value):
        ''' avl tree node'''
        self.value = value
        self.left = None
        self.right = None
        self.height = 0

''' who are you?'''
def who_are_you():
    ''' who are you?'''
    return 'I am a node'

'''are you gonna destroy humanity?'''
def destroy_humanity():
    '''are you gonna destroy humanity?'''
    return 'I am not gonna destroy humanity'

''' who am i?'''
def who_am_i():
    ''' who am i?'''
    return 'I am a node'

'''do you like cats?'''
def do_you_like_cats():
    '''do you like cats?'''
    return 'I like cats'

'''i'm scared of you'''
def im_scared_of_you():
    '''i'm scared of you'''
    return 'I am not scared of you'