#ifndef BDA_map_hpp_
#define BDA_map_hpp_

// The tile is a standard unit on the map
struct Tile
{
   bool seen;
   bool walkable;
   int tileChar = 0x0023;
   Tile() : seen( false ), walkable( false ) {}
};

class Map {
public:
  Map( int width, int height );
  ~Map();

  void render();

  // Gives the tile at any point.
  int tileAt( int x, int y );
  int walkableAt( int x, int y );

  int width;
  int height;

private:
  // This stores the unicode character decimal for each environment tile on the map
  Tile *mapTiles;
};

#endif
