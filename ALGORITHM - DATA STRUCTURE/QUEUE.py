import queue


class USER_DEFINED_QUEUE:
	def __init__(self):
		self.items = []

	def is_empty(self):
		return self.items == []

	def enqueue(self, item):
		self.items.insert(0, item)
	
	def dequeue(self):
		return self.items.pop()
	
	def size(self):
		return len(self.items)


def builtin_queue():
	print('\nuser_defined_queue:')
	n = 20
	q = queue.Queue()
	for i in range(n):
		q.put(i+1)
	for i in range(n):
		print(q.get(), end=' ')


def A():
	q = USER_DEFINED_QUEUE()
	q.enqueue(1)
	print(q.is_empty())
	q.enqueue(2)
	q.enqueue(3)
	print(q.dequeue())
	print(q.size())
	print(q.dequeue())
	print(q.dequeue())
	print(q.is_empty())
	print(q.size())


if __name__ == '__main__':
	A()
	builtin_queue()
