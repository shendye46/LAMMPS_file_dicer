#include <iostream>
#include <locale>
#include <set>
#include <sstream>
#include <chrono>
#include <thread>
#include "reader.h"



typedef enum Direction{
    x = 0,
    y = 1,
    z = 2
}Direction;
bool belongsTobin(double min, double max,double val){
    return val>=min && val < max;
}
std::string convertDirToString(Direction direction){
    std::string res;
    switch (direction)
    {
    case x:
        res="x";
        break;
    case y:
        res="y";
        break;
    case z:
        res="z";
        break;
    
    default:
        break;
    }
    return res;
}
template<typename T>
std::string tostring(const T &n) {
    std::ostringstream oss;
    oss << n;
    std::string s =  oss.str();
    int dotpos = s.find_first_of('.');
    if(dotpos!=std::string::npos){
        int ipos = s.size()-1;
        while(s[ipos]=='0' && ipos>dotpos){
            --ipos;
        }
        s.erase ( ipos + 1, std::string::npos );
    }
    return s;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: file.cfg min_double max_double direction_char(0,1,2) \n";
        return 1;
    }
    Direction direction;
    double min, max;
    std::ifstream in(argv[1]);
    min = std::stod(argv[2]);
    max = std::stod(argv[3]);
    direction = static_cast<Direction>(std::stoi(argv[4]));
    std::ofstream out;


    std::string text_line;
    Point3d p;
    int i=0;

    std::string filename = convertDirToString(direction)+"_"+tostring(min)+"_"+tostring(max)+".cfg";
    out.open("temp.txt");
    while (i<9)
    {
        std::getline(in,text_line);
        // out<<text_line<<"\n";
        i++;
    }
    int atoms= 0;
    while (in>>p)
    {
           switch (direction)
           {
           case x:
           {
               if(belongsTobin(min,max,p.x))
                {
                atoms++;    
                out<<p.id<<" "<<p.molId<<" "<<p.x<<" "<<p.y<<" "<<p.z<<"\n";
                }
            break;
           }
           case y:
           {
               if(belongsTobin(min,max,p.y))
               {
                atoms++;
                out<<p.id<<" "<<p.molId<<" "<<p.x<<" "<<p.y<<" "<<p.z<<"\n";
               }
            break;
           }
           case z:
           {
               if(belongsTobin(min,max,p.z))
               {
                atoms++;
                out<<p.id<<" "<<p.molId<<" "<<p.x<<" "<<p.y<<" "<<p.z<<"\n";
               }
            break;
           }
           default:
               break;
           }
        
    }
    out.close();
    std::string replace= "sed -i '4s/.*/"+tostring(atoms)+"/' ../head.txt";
    system(replace.c_str());
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //merge head.txt with out
    std::string copycommand = "scp ../head.txt temphead.txt";
    system(copycommand.c_str());
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    //std::cout<<"No. of atoms: "<<atoms<<std::endl;
    std::string catcommand = "cat temphead.txt temp.txt >> "+filename;
    system(catcommand.c_str()); 

}

    

