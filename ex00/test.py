import subprocess

#ERROR_TEST
def	test_Error_arg():
	result = subprocess.run(['./convert'], capture_output=True, text=True)
	assert result.stderr == "arg is invalid\n" 

def	test_NO_Type():
	result = subprocess.run(['./convert', 'aaaaaaa'], capture_output=True, text=True)

	expected = 'input is invalid\n'
	assert result.stderr == expected

#test_example
def test_42():
	result = subprocess.run(['./convert', '42.0f'], capture_output=True, text=True)

	expected = 'char: \'*\'\n'\
				'int: 42\n'\
				'float: 42.0f\n'\
				'double: 42.0\n'
	# assert result.stdout == "char: \'*\'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n" 
	assert result.stdout == expected

def test_0():
	result = subprocess.run(['./convert', '0'], capture_output=True, text=True)

	expected = 'char: Non displayable\n'\
				'int: 0\n'\
				'float: 0.0f\n'\
				'double: 0.0\n'
	# assert result.stdout == "char: \'*\'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n" 
	assert result.stdout == expected


#test_char
def	test_a():
	result = subprocess.run(['./convert', 'a'], capture_output=True, text=True)

	expected = 'char: \'a\'\n'\
				'int: impossible\n'\
				'float: impossible\n'\
				'double: impossible\n'

	assert result.stdout == expected

	