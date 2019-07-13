#ifndef BDA_bresenham_hpp_
#define BDA_bresenham_hpp_

struct Point
{
  float x;
  float y;
  Point( float x, float y ) : x( x ), y( y ) {}
};

class BresenhamLineDrawer
{
public:
  BresenhamLineDrawer();
  ~BresenhamLineDrawer();

  bool step( Point &point );
  bool recalculate( Point p0, Point p1 );

  int setSize;
private:
  std::vector<Point> pointSet;
};

// Helper functions

float lerp( float v0, float v1, float t );
struct Point lerp2d( Point p0, Point p1, float t );

#endif // BDA_bresenham_hpp_
