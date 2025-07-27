import collections


class USER_DEFINED_DEQUE:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addRear(self, item):
        self.items.append(item)

    def addFront(self, item):
        self.items.insert(0, item)

    def removeFront(self):
        return self.items.pop(0)

    def removeRear(self):
        return self.items.pop()

    def size(self):
        return len(self.items)


def builtin_deque():
    print('\ndeque_right:')
    n = 10
    q = collections.deque()
    for i in range(n):
        q.append(i + 1)
    for i in range(n):
        print(q.popleft(), end=' ')

    print('\ndeque_left:')
    n = 10
    q = collections.deque()
    for i in range(n):
        q.appendleft(-i)
    for i in range(n):
        print(q.pop(), end=' ')


def A():
    d = USER_DEFINED_DEQUE()
    print(d.isEmpty())
    d.addRear(8)
    d.addRear(5)
    d.addFront(7)
    d.addFront(10)
    print(d.size())
    print(d.isEmpty())
    d.addRear(11)
    print(d.removeRear())
    print(d.removeFront())
    d.addFront(55)
    d.addRear(45)
    print(d.items)


if __name__ == '__main__':
    A()
    builtin_deque()
