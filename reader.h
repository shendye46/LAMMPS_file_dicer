#include <iostream>
#include <fstream>
#include <sstream>

struct Point3d
{
  int id, molId;
  double x, y, z;
  friend std::istream& operator>>(std::istream& input, Point3d& p);
};
std::istream& operator>>(std::istream& input, Point3d& p)
{
  input>>p.id>>p.molId>> p.x >> p.y >> p.z;
  return input;
}