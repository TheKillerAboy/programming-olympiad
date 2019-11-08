from sys import argv
from os import listdir, popen
from os.path import isfile, join
from types import SimpleNamespace

def flagToNickname(flag, nicknames):
	if flag in nicknames:
		return nicknames[flag]
	return flag


def parseValue(value):
	if value.lower() in {"true","false","t","f"}:
		return value.lower()[0] == "t"
	try:
		value = int(value)
		return value
	except:
		pass
	return value

def parseArgv(method, nicknames = {}):
	args = iter(argv[1:])
	__args = []
	__kwargs = {"prefixOnly" : False, "timeLimit_ms" : 2000, "inputExt" : '.in', "outputExt" : '.out', "outputNeeded" : False, "capSensitive" : False, "showError" : False}
	while True:
		try:
			value = next(args)
			if(value[:2] == '--'):
				__kwargs[flagToNickname(value[2:],nicknames)] = parseValue(next(args))
			elif value[0] == '-':
				__kwargs[flagToNickname(value[1:],nicknames)] = parseValue(next(args))
			else:
				__args.append(value)
		except:
			break
	method(*__args,**__kwargs)

def fileMeetConstraints(file, files_in_direcory,source_file,prefixOnly,inputExt,outputExt,outputNeeded,capSensitive,**kwargs):
	def wordCapSensitiveEq(check, word):
		return check == word if capSensitive else check.lower() == word.lower()

	if prefixOnly and not wordCapSensitiveEq(source_file,file[:len(source_file)]):
		return False

	if inputExt not in file:
		return False

	if outputNeeded and file.replace(inputExt,outputExt) not in files_in_direcory:
		return False

	return True

def tester(directory,source_file,*args,**kwargs):
	num_of_tests = 0
	num_of_correct = 0
	KWARGS = SimpleNamespace(**kwargs)
	files_in_direcory = {f for f in listdir(directory) if isfile(join(directory, f))}
	for file in files_in_direcory:
		if fileMeetConstraints(file,files_in_direcory,source_file,**kwargs):
			output_file = file.replace(KWARGS.inputExt,KWARGS.outputExt)

			terminal_return = popen(f'timeout {KWARGS.timeLimit_ms/1000} "{directory}/{source_file}" < "{directory}/{file}" | diff -E -Z -b "{directory}/{output_file}" -')

			num_of_tests += 1
			print(file[:file.find('.')], end = ' ')
			if terminal_return.read() == '':
				print(" Correct!")
				num_of_correct += 1
			else:
				print(" Incorrect :(")
				if KWARGS.showError:
					print("Error Occoured: ", terminal_return.read())
	if num_of_tests > 0:
		print("Result: ",f"{num_of_correct}/{num_of_tests}",f"{num_of_correct/num_of_tests:.2%}")
	else:
		print("No tests found.")

if __name__ == '__main__':
	parseArgv(tester,{'p':"prefixOnly"})