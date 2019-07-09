#ifndef BDA_map_hpp_
#define BDA_map_hpp_

class Map {
public:
    Map();
    ~Map();
private:
    // This stores the unicode character decimal for each tile on the map
    int Tiles[MAP_SIZE];
};

#endif