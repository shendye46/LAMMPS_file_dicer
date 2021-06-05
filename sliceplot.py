import matplotlib.pyplot as plt
import argparse
import sys
import matplotlib
matplotlib.use('tkAgg')


def getDirectionFromPath(path):
    if "x_" in path:
        return 3,4
    elif "y_" in path:
        return 2,4
    elif "z_" in path:
        return 2,3

    
def readAndProcessSlice(path):
    x_axis, y_axis = getDirectionFromPath(path)
    count=0
    
    x=[]
    y=[]
    with open(path,'r') as file:
        for line in file:
            if(count<9):
                count+=1
            else:
                x.append(float(line[:-1].split(" ")[x_axis]))
                y.append(float(line[:-1].split(" ")[y_axis]))
    return x, y

def plot(path,size):
    X,Y = readAndProcessSlice(path)
    plt.scatter(X,Y,s=size)
    plt.show()
    
def parse(args):
    if(len(sys.argv)<3):
        print("usage: python sliceplot.py plot -f<file> -s<atom_size:int>")
        sys.exit(-1)
    plot(args.path,args.atom_size)
    

if __name__=='__main__':
    parser = argparse.ArgumentParser(prog="plot")
    parser.add_argument('-f','--path',type=str,help="enter file path")
    parser.add_argument('-s','--atom_size', type=int, help='enter atom size in int, float values are not supported by matplotlib size')
    args = parser.parse_args()
    parse(args)