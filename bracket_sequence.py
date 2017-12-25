with open("input.txt", 'r') as inf:
	n = int(inf.readline())
	for _ in range(n):
		stack = []
		seq = [s for s in inf.readline() if s != "\n"]
		i = 0
		d = len(seq)
		check = True
		while i < d and check:
			if seq[i] in ['(', '[']:
				stack.append(seq[i])
				i+= 1
			elif len(stack) > 0:
				p = stack.pop()
				if p == '[' and seq[i] == ')' or p == '(' and seq[i] == ']':
					check = False
				else:
					i+=1
			else:
				check = False

		if len(stack) == 0 and check:
			print("YES")
		else:
			print("NO")

