#ifndef BDA_tiles_hpp_
#define BDA_tiles_hpp_

// The tile is a standard unit on the map
struct Tile
{
  // Has the player seen this tile?
  bool seen;
  // Can an actor exist on this tile?
  bool walkable;
  // What is the Unicode symbol for this tile.
  int glyph;
  // Foreground and Background of the environment. ENVIRONMENT MUST ALWAYS EXIST ON THE BOTTOM RENDER LAYER OR BK WON'T WORK!
  std::string fcolor, bcolor;
  // Sets default values
  Tile( bool seen, bool walkable, int glyph, const char* fcolor, const char* bcolor ) : seen( seen ), walkable( walkable ), glyph( glyph ), fcolor( fcolor ), bcolor( bcolor ) {}
};

#endif // BDA_tiles_hpp_
