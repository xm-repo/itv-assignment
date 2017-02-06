import os
import random
import string
from sys import argv

def random_string(min_length, max_length):
	letters	= string.lowercase + string.uppercase + string.digits
	return ''.join(random.choice(letters) for i in xrange(random.randint(min_length, max_length)))

def random_file(folder, min_length, max_length):
	file_name = random_string(min_length, max_length) + os.extsep + random_string(3,3)
	return os.path.join(folder, file_name)

if __name__ == "__main__":

	if len(argv) < 3:
		print("random_files.py target_folder files_count")
		raise SystemExit

	target_folder, files_count = argv[1], int(argv[2])
	name_length = (1, 10) #(min, max)
	file_length = (10, 100) #(min, max)
	word_length = (1, 10) #(min, max)

	#create target folder
	if not os.path.exists(target_folder):
		os.makedirs(target_folder)

	#initialize the random number generator.
	random.seed()

	words_count = 0

	#create files with random names
	for i in xrange(files_count):

		with open(random_file(target_folder, *name_length), 'w') as file:

			file.write(" " * random.randint(*word_length))

			#write random space-delimited words in file
			for j in xrange(random.randint(*file_length)):
				next_word = random_string(*word_length) + (" " * random.randint(*word_length))
				file.write(next_word)

		words_count += (j + 1) #save word count
		print(os.path.basename(file.name) + " " + str(j + 1))

	print("words_count: " + str(words_count))
