#include "geo1.h"
#include "geo2.h"

#include <iostream>

void Point3d::print() const
{
  std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

void Point3d::moveByVector(const Vector3d& v){
  m_x += v.m_x;
  m_y += v.m_y;
  m_z += v.m_z;
  // implement this function as a friend of class Vector3d
}
