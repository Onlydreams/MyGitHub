import os
import pickle
from nester import print_lol
os.getcwd()
os.chdir('D:\\workspace\python\HeadFirstPython\chapter3')
os.getcwd()

man = []
other = []

try:
        data = open('sketch.txt')
        for each_line in data:
                try:
                        (role, line_spoken) = each_line.split(':', 1)
                        line_spoken = line_spoken.strip()
                        if role == 'Man':
                                man.append(line_spoken)
                        elif role == 'Other Man':
                                other.append(line_spoken)
                except ValueError:
                        pass
        data.close()
except IOError:
        print('The data is missing!')

try:
        with open('man.txt', 'wb') as man_out:#wb表示以二进制打开数据文件
                pickle.dump(man, man_out)
        with open('other.txt', 'wb') as other_out:
                pickle.dump(other, other_out)
except IOError as err:#给异常对象一个名
        print('File error: ' + str(err))
except pickle.PickleError as perr:
        print('Pickling error: ' + str(perr))
