#include "main.hpp"

/*
 * MAP FILE
 *
 * The map is the environment in which the game takes place. Map generation is also handled here.
 *
 */

Map::Map( int width, int height ) : width( width ), height( height )
{
  // This is an array of the tiles on the map.
  mapTiles = new Tile[width * height];

  // TEMPORARY: This fills the rectangle with middle dots.
  for( int x = 1; x < width - 1; ++x )
  {
    for( int y = 1; y < height - 1; ++y )
    {                                 // '·'
      mapTiles[x + y * 119].tileChar = 0x00B7;
      mapTiles[x + y * 119].walkable = true;
    }
  }
}

Map::~Map()
{
  delete [] mapTiles;
}

void Map::render()
{
  // This just renders the tile map.
  for( int x = 0; x < width; ++x )
  {
    for( int y = 0; y < height; ++y )
    {
      terminal_put( x, y, mapTiles[x + y * 119].tileChar );
    }
  }
}

int Map::tileAt( int x, int y )
{
  return mapTiles[x + y * 119].tileChar;
}

int Map::walkableAt( int x, int y )
{
  return mapTiles[x + y * 119].walkable;
}
