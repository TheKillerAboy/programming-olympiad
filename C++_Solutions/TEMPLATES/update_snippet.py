import sys

args = sys.argv[1:]
snippets_dir = "/mnt/c/Users/Annekin/AppData/Roaming/Sublime Text 3/Packages/User"

def txt_to_snippet(text, trigger):
	return f"""<snippet>
  <content><![CDATA[
{text}
]]></content>
  <tabTrigger>{trigger}</tabTrigger>
</snippet>"""

def get_text_trigger():
	file = args[0]
	text =""
	with open(file,'r') as f:
		text = ''.join(f.readlines())
	return text,file[:file.find('.')]

def write_snippet(snippet,name):
	with open(f"{snippets_dir}/{name}.sublime-snippet",'w') as f:
		f.write(snippet)

if __name__ == '__main__':
	text, trigger = get_text_trigger()
	snippet = txt_to_snippet(text,trigger)
	write_snippet(snippet, trigger)
