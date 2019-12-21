def get_Z():
    if peek() == 'c':
        get_A()
        get(c)
        get_B()
    elif peek() == 'a':
        get_B()
        get(d)
    else:
        panic()

def get_A():
    get(c)
    while peek() == 'a':
        get(a)
        get_B()

def get_B():
    get(a)
    if peek() == 'c':
        get_A()