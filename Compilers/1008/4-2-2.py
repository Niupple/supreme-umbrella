def get_A():
    if peek() == '(':
        get('(')
        get_B()
        get(')')
    else:
        get(d)
        get_B()
        get(e)

def get_B():
    if peek() == c:
        get(c)
    else:
        get_B()