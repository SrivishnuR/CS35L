import string
import sys
import locale
from optparse import OptionParser

def main():
    locale.setlocale(locale.LC_COLLATE, 'C')
    usage_msg = "%prog [OPTION]... FILE1 FILE2"
    parser = OptionParser(usage=usage_msg)
    parser.add_option("-1", action='store_true', dest="arg1", 
                      help="suppress first column of output")
    parser.add_option("-2", action='store_true', dest="arg2", 
                      help="suppress second column of output")
    parser.add_option("-3", action='store_true', dest="arg3", 
                      help="suppress third column of output")
    parser.add_option("-u", action='store_true', dest="argu", 
                      help="allow input of unsorted files")
    options, args = parser.parse_args(sys.argv[1:])

    if len(args) != 2:
        parser.error("wrong number of operands")

    if args[0] == "-":
        inputfile1 = sys.stdin.readlines()
    else:
        f = open(args[0], 'r')
        inputfile1 = f.readlines()
        f.close()

    if args[1] == "-":
        inputfile2 = sys.stdin.readlines()
    else:
        f = open(args[1], 'r')
        inputfile2 = f.readlines()
        f.close()
        
    col1 = []
    col2 = []
    col3 = []
    
    match = False

    for l1 in inputfile1:
        for l2 in inputfile2:
            if l1 == l2:
                match = True
                break

        if match:
            col1.append("")
            col2.append("")
            col3.append(l1)
        else:
            col1.append(l1)
            col2.append("")
            col3.append("")
            
        match = False

    for l2 in inputfile2:
        for l1 in inputfile1:
            if l2 == l1:
                match = True
                break

        if not match:
            col1.append("")
            col2.append(l2)
            col3.append("")
            
        match = False

    toprint = True

    if not options.argu:
        if not (inputfile1 == sorted(inputfile1)):
            print ("comm: file 1 is not in sorted order")
            toprint = False
        if not (inputfile2 == sorted(inputfile2)):
            print ("comm: file 2 is not in sorted order")
            toprint = False

    if toprint:
        for i in range(len(col1)):
            println = ""
            toprint = False

            if not options.arg1:
                if not (col1[i] == ""):
                    toprint = True
            
                println = println + col1[i].strip()
                println = println + '\t'

            if not options.arg2:
                if not (col2[i] == ""):
                    toprint = True
            
                println = println + col2[i].strip()
                println = println + '\t'

            if not options.arg3:
                if not (col3[i] == ""):
                    toprint = True
            
                println = println + col3[i].strip()

            if toprint:
                print(println)

main();
