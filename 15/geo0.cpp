#include "geo1.h"
#include "geo2.h"

int main()
{
  Point3d p { 1.0, 2.0, 3.0 };
  Vector3d v { 2.0, 2.0, -3.0 };

  p.print();
  p.moveByVector(v);
  p.print();

  return 0;
}
