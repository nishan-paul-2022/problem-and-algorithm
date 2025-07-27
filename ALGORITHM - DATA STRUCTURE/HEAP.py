
class Heap:
    def __init__(self):
        self.tree = [None]
        self.number = 0

    def _heapify(self, value):
        self.number += 1
        self.tree.append(value)
        child_idx = self.number
        parent_idx = int(child_idx / 2)

        while parent_idx >= 1:
            parent = self.tree[parent_idx]
            child = self.tree[child_idx]
            if parent < child:
                self.tree[parent_idx] = child
                self.tree[child_idx] = parent
                child_idx = parent_idx
                parent_idx = int(child_idx / 2)
            else:
                break

    def push(self):
        values = list(map(int, input().split()))
        for i in values:
            self._heapify(i)

    def pop(self):
        root = 1
        last = self.number
        self.tree[root], self.tree[last] = self.tree[last], self.tree[root]
        del self.tree[last]
        self.number -= 1

        parent_idx = 1
        while parent_idx <= self.number:
            parent = self.tree[parent_idx]
            child, child_idx = None, None
            left, right = parent_idx * 2, parent_idx * 2 + 1

            if left <= self.number:
                child_idx = left
                child = self.tree[child_idx]

            if right <= self.number:
                if child < self.tree[right]:
                    child_idx = right
                    child = self.tree[child_idx]

            if child_idx is not None and parent < child:
                self.tree[parent_idx], self.tree[child_idx] = child, parent
                parent_idx = child_idx
            else:
                break

    def print_heap(self):
        print(self.tree)
        for i in range(1, self.number+1):
            print(self.tree[i])


if __name__ == '__main__':
    heap = Heap()
    heap.push()
    heap.print_heap()
    heap.pop()
    heap.print_heap()

# MAX HEAP
# 1 2 3 4 5 6 7 8 9 10
