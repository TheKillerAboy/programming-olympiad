from sys import argv
import os;

mypath = os.path.dirname(os.path.realpath(__file__))
source_file = argv[1];

from os import listdir, popen
from os.path import isfile, join

onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]

total = 0
correct = 0

for file in onlyfiles:
	if file.find('.in') != -1:
		out_file = file.replace('.in','.out.test');
		real_out_file = file.replace('.in','.out');
		f = popen(f'./{source_file} < {file} > {out_file}; cmp {out_file} {real_out_file}')
		total += 1
		if f.read() == '':
			print(file.replace('.in','')," Correct!")
			correct += 1
		else: 
			print(file.replace('.in','')," Incorrect :(")

print(f'{correct/total:.2%}')
