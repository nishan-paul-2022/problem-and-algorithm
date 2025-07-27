
class PriorityQueue:
    def __init__(self):
        self.tree = [(None,None)]
        self.number = 0

    def _heapify(self, value):
        self.number += 1
        self.tree.append(value)
        child_idx = self.number
        parent_idx = int(child_idx / 2)

        while parent_idx >= 1:
            parent = self.tree[parent_idx][1]
            child = self.tree[child_idx][1]
            if parent < child:
                self.tree[parent_idx], self.tree[child_idx] = self.tree[child_idx], self.tree[parent_idx]
                child_idx = parent_idx
                parent_idx = int(child_idx / 2)
            else:
                break

    def push(self):
        values = list(map(str, input().split()))
        for i in range(len(values)):
            values[i] = tuple(map(int, values[i].split(',')))
        print(values)
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
            parent = self.tree[parent_idx][1]
            child, child_idx = None, None
            left, right = parent_idx * 2, parent_idx * 2 + 1

            if left <= self.number:
                child_idx = left
                child = self.tree[child_idx][1]

            if right <= self.number:
                if child < self.tree[right][1]:
                    child_idx = right
                    child = self.tree[child_idx][1]

            if child_idx is not None and parent < child:
                self.tree[parent_idx], self.tree[child_idx] = self.tree[child_idx], self.tree[parent_idx]
                parent_idx = child_idx
            else:
                break

    def print_heap(self):
        for i in range(1, self.number+1):
            print(self.tree[i])


if __name__ == '__main__':
    priority_queue = PriorityQueue()
    priority_queue.push()
    priority_queue.print_heap()
    priority_queue.pop()
    priority_queue.print_heap()

# 1,11 2,12 3,14 4,15 5,16 6,17 7,18 8,19 9,20 10,21
# [(1,11), (2,12), (3,14), (4,15), (5,16), (6,17), (7,18), (8,19), (9,20), (10,21)]
