def matrixFill(n, m, M):
	"""
	Matrix fill algorithm from a Microsoft interview question.
	Given a matrix of size n x m filled with 0's and 1's

	e.g.:

	1 1 0 1 0

	0 0 0 0 0

	0 1 0 0 0

	1 0 1 1 0

	if the matrix has 1 at (i,j), fill the column j and row i with 1's

	i.e., we get:

	1 1 1 1 1

	1 1 1 1 0

	1 1 1 1 1

	1 1 1 1 1

	Required complexity: O(n*m) time and O(1) space

	Assume M is an array of arrays (M[][]).
	NOTE: you are not allowed to store anything except '0' or '1' in the matrix entries
	:param n: number of rows
	:param m: number of columns
	:return:
	"""

	def scanRow(i):
		# Returns 0 if there are no 0s in the row, 1 otherwise
		for c in range(m):
			if M[i][c] == 1:
				return 1
		return 0

	def scanColumn(i):
		# Returns 0 if there are no 0s in the column, 1 otherwise
		for c in range(n):
			if M[c][i] == 1:
				return 1
		return 0

	fRow = scanRow(0)
	fColumn = scanColumn(0)

	for i in range(1, m):
		M[0][i] = scanColumn(i)

	for i in range(1, n):
		M[i][0] = scanRow(i)

	for i in range(1, n):
		for j in range(1, m):
			if M[i][0] == 1 or M[0][j] == 1:
				M[i][j] = 1
			else:
				M[i][j] = 0

	if fRow == 1:
		for i in range(m):
			M[0][i] = 1
	if fColumn == 1:
		for i in range(n):
			M[i][0] = 1


	return M
def printMatrix(n, m, M):
	for i in range(n):
		print(M[i])

M = [[1, 1, 0, 1, 0], [0, 0, 0, 0, 0], [0, 1, 0, 0, 0], [1, 0, 1, 1, 0]]
printMatrix(4, 5, M)
M = matrixFill(4, 5, M)
print()
printMatrix(4, 5, M)

