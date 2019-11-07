from sys import argv
import os;

mypath = argv[1]
source_file = argv[2]
preset_type = argv[3]
asource = preset_type == "prefix"

from os import listdir, popen
from os.path import isfile, join

onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]

total = 0
correct = 0

for file in onlyfiles:
	if file.find('.in') != -1:
		if asource and file.find(source_file) == -1:
			continue
		out_file = file.replace('.in','.out.test');
		real_out_file = file.replace('.in','.out');
		f = popen(f'{mypath}/{source_file} < {mypath}/{file} > {mypath}/{out_file}; diff -E -Z -b {mypath}/{out_file} {mypath}/{real_out_file}')
		total += 1
		if f.read() == '':
			print(file.replace('.in','')," Correct!")
			correct += 1
		else: 
			print(file.replace('.in','')," Incorrect :(")

print(f'{correct/total:.2%}')
