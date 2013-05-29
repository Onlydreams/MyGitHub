import sys

def print_lol(the_list, indent=False, level=0, fh=sys.stdout):#标准输出sys.stdout是在标准库的sys模块中导入
#第四个参数fh用来标识将把数据写入哪个位置
    for each_item in the_list:
        if isinstance(each_item, list):
            print_lol(each_item, indent, level+1, fh)
        else:
            if indent:
                for num in range(level):
                    print("\t", end='', file=fh)
            print(each_item, file=fh)
