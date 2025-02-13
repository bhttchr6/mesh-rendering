#pragma once

#include <vector>
#include <string>
#include "geometry.hpp"

class Model
{

public:
    int getNumVertices();
    int getNumFaces();
    Vec3f getVertCoords(int i);
    std::vector<int> getFaceIds(int idx);
    Model();
    Model(std::string filename);
    ~Model();

private:
    std::vector<Vec3f> vertexCoords_;
    std::vector<std::vector<int>> face_;

    int numVertices_;
    int numFaces_;

};
