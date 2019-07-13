#include "main.hpp"

/*
 * MAP FILE
 *
 * The map is the environment in which the game takes place. Map generation is also handled here.
 *
 */

Map::Map( int width, int height ) : width( width ), height( height )
{
  {
    std::vector<Tile> temp( width * height, Tile( false, false, 0x0023, "darker green", "darkest grey" ) );
    std::swap( temp, mapTiles );
  }

  // TEMPORARY: This fills the rectangle with middle dots.
  for( int x = 1; x < width - 1; ++x )
  {
    for( int y = 1; y < height - 1; ++y )
    {
      mapTiles[x + y * width] = dungeonFloorOne;
    }
  }
}

Map::~Map()
{

}

void Map::render()
{
  // This just renders the tile map.
  for( int x = 0; x < width; ++x )
  {
    for( int y = 0; y < height; ++y )
    {
      terminal_color( color_from_name(mapTiles[x + y * width].fcolor.c_str()) );
      terminal_bkcolor( color_from_name(mapTiles[x + y * width].bcolor.c_str()) );
      terminal_put( x, y, mapTiles[x + y * width].glyph );
    }
  }
}

int Map::tileAt( int x, int y )
{
  return mapTiles[x + y * width].glyph;
}

int Map::walkableAt( int x, int y )
{
  return mapTiles[x + y * width].walkable;
}
