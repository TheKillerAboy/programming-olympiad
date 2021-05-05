import os
import re
try:
    import fire
except:
    print('run: pip install fire')

class CLI:
    ignores = [r'/\.git/']
    def __in_ignores(self, file):
        for ignore in self.ignores:
            if re.search(ignore, file):
                return True
        return False

    def __get_exes(self):
        for root, dirs, files in os.walk('.'):
            for file in files:
                file = os.path.join(root, file)
                if not self.__in_ignores(file):
                    if os.access(file, os.X_OK) or re.search(r'\.exe$', file):
                        yield file

    def rm_exes(self, ignores=[]):
        self.ignores.extend(ignores)

        exes = list(self.__get_exes())
        print('\n'.join(exes))
        if input('Remove all(Y/n)? ') == 'Y':
            for exe in exes:
                os.remove(exe)
                print(f'Removed {exe}')

    def __humanbytes(self, B):
        B = float(B)
        KB = float(1024)
        MB = float(KB ** 2) # 1,048,576
        GB = float(KB ** 3) # 1,073,741,824
        TB = float(KB ** 4) # 1,099,511,627,776

        if B < KB:
            return '{0} {1}'.format(B,'Bytes' if 0 == B > 1 else 'Byte')
        elif KB <= B < MB:
            return '{0:.2f} KB'.format(B/KB)
        elif MB <= B < GB:
            return '{0:.2f} MB'.format(B/MB)
        elif GB <= B < TB:
            return '{0:.2f} GB'.format(B/GB)
        elif TB <= B:
            return '{0:.2f} TB'.format(B/TB)

    def ln_exes(self, ignores=[]):
        self.ignores.extend(ignores)
        total = 0
        for exe in self.__get_exes():
            total += os.stat(exe).st_size
        print(self.__humanbytes(total))

if __name__ == '__main__':
    fire.Fire(CLI())
