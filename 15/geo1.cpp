#include "geo1.h"

#include <iostream>

void Vector3d::print() const
{
  std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}
