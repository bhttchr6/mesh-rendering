#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Model.hpp"


Model::Model(){std::cout << "No model provided" << std::endl;}


Model::Model(std::string filename)
{
    std::ifstream file;
    std::string line;
    file.open(filename);
    if(file.is_open())
    {
        while(!file.eof())
        {
            std::getline(file, line);
            std::istringstream iss(line);

            if(!line.compare(0, 2, "v "))  // here line.compare(..) return a 0, so !0 is actually 1, which means true
            {
                // read vertices coordinates
                
                char c1;
                double v1, v2, v3;
                iss >> c1 >> v1 >> v2 >> v3;
                Vec3f v(v1, v2, v3);
                
                vertexCoords_.push_back(v);
                
            }
            else if(!line.compare(0, 2, "f "))
            {
                /*
                //read vertex indices for each face
                char trash;
                int trash1, trash2, trash3, trash4, trash5, trash6, idx1, idx2, idx3;
                iss >> trash >> idx1 >> trash1 >> trash2 >> idx2 >> trash3 >> trash4 >> idx3 >> trash5 >> trash6; 
                std::cout << idx1 <<idx2 <<idx3<<std::endl;
                std::vector<int> vertices;
                vertices.push_back(idx1--);
                vertices.push_back(idx2--);
                vertices.push_back(idx3--);
                face_.push_back(vertices);
                */
                std::vector<int> f;
                char trash;
                int itrash, idx;
                iss >> trash;
                while (iss >> idx >> trash >> itrash >> trash >> itrash) {
                    idx--; // in wavefront obj all indices start at 1, not zero
                    f.push_back(idx);
                }
                face_.push_back(f);
                

            }
        }

    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    numVertices_ = vertexCoords_.size();
    numFaces_ = face_.size();



}

Model::~Model(){};


int Model::getNumVertices()
{
    return numVertices_;
}

int Model::getNumFaces()
{
    return numFaces_;
}

Vec3f Model::getVertCoords( int vertexId)
{
    return vertexCoords_[vertexId];
}

std::vector<int> Model::getFaceIds(int faceId)
{
    return face_[faceId];
}