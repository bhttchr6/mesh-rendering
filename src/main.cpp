#include "tgaimage.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "utils.hpp"
#include "Model.hpp"

/*
Code for rendering obj files
written by Anurag Bhattacharyya
Reference: https://github.com/ssloy/tinyrenderer/wiki

*/




int main(int argc, char** argv) {
	
	frame frame;
	frame.width = 800;
	frame.height = 800;

	TGAImage image(frame.width, frame.height, TGAImage::RGB);

	std::string filename = "./assets/head.obj";
	//read the model
	Model* model = new Model(filename);
	int numVertices = model->getNumVertices();
	int numFaces = model->getNumFaces();
	std::cout << "Number of vertices: " << numVertices << std::endl;
	std::cout << "Number of faces: " << numFaces << std::endl;


	//draw the mesh
	for(int i = 0; i < numFaces; i++)
	{
		// read each face and get the vertices for that face
		std::vector<int> vertIds;
		vertIds = model->getFaceIds(i);
		
		for(size_t j= 0; j < vertIds.size(); j++)
		{
			
			Vec3f coordsStart, coordsFinish;
			coordsStart = model->getVertCoords(vertIds[j]);
			coordsFinish = model->getVertCoords(vertIds[(j + 1)%3]);
			drawSegment(coordsStart, coordsFinish, image, frame);
			
		}
		
	}

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");

	delete model;
	return 0;
}

