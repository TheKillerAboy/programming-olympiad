replace_dict = {
    'E':'3',
    "L":"1",
    "O":'0',
    "G":"9",
    "B":"8"
}
replace_dict = {v:k for k,v in replace_dict.items()}

if __name__ == '__main__':
    message = input('Enter message: ')
    true_message = ''
    for letter in message:
        if letter in replace_dict.keys():
            true_message+=replace_dict[letter]
        else:
            true_message+=letter
    print(true_message)