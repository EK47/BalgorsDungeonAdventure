#include "main.hpp"

/*
 * BRESENHAM FILE
 *
 * The is an implementation of Bresenham's Line Drawing Algorithm based on Red Blob Game's Blog Article.
 *
 */

// This is a generic linear interpolation function
float lerp( float v0, float v1, float t )
{
  if( v1 < v0 )
  {
    std::swap( v1, v0 );
  }
  return v0 + t * ( v1 - v0 );
}

// This is a 2d linear interpolation functions that returns a point between two points.
struct Point lerp2d( Point p0, Point p1, float t )
{
  return Point( lerp( p0.x, p1.x, t ), lerp( p0.y, p1.y, t ) );
}

struct Point roundPoint( Point point )
{
  return Point( static_cast<int>(point.x), static_cast<int>(point.y) );
}

// This initializes the line. It calls recalculate although it is the first calculation. Less Code.
BresenhamLineDrawer::BresenhamLineDrawer() {}

BresenhamLineDrawer::~BresenhamLineDrawer() {}

// This gives the next point in the internal vector to whomever calls the function. The point is then removed from the internal vector.
bool BresenhamLineDrawer::step( Point& point )
{
  // Since the pointSet was loaded in reverse order, the next step is the last element in the vector. Update the outside point, then delete the current step ( current
  // for the outside variable ) from the pointSet.
  point = pointSet.back();
  pointSet.pop_back();
  return true;
}

// This calculates the points in the internal vector.
bool BresenhamLineDrawer::recalculate( Point p0, Point p1 )
{
  // Diagonal distance is used to prevent overdraw and underdraw
  int diag_distance = round( hypot((p1.x - p0.x), (p1.y - p0.y)) );
  if( diag_distance <= 0 )
  {
    // The distance cannot be less than zero. Something is wrong.
    return false;
  }
  // This loads the vector with all points in the line
  for( int step = 0; step <= diag_distance; ++step )
  {
    // The current step in the evenly spaced dot placement. If I don't cast one of these integers to a float, integer division occurs instead of float divison.
    float t = static_cast<float>(step) / diag_distance;
    // Note: Starting at the ending points loads the vector in backwards order. This makes step( Point &point )'s job easier.
    pointSet.push_back( roundPoint( lerp2d( p1, p0, t ) ) );
  }

  int setSize = pointSet.size();
  return true;
}
