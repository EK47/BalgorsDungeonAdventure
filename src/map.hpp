#ifndef BDA_map_hpp_
#define BDA_map_hpp_

extern Tile dungeonWallOne;
extern Tile dungeonFloorOne;

class Map
{
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
  std::vector<Tile> mapTiles;
};

#endif // BDA_map_hpp_
