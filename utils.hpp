#pragma once

#include "geometry.hpp"


const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

struct frame
{
	int width;
	int height;

};

struct point2d
{
	float x;
	float y;
	point2d(): x{0.0}, y{0.0} {};
	point2d(float xin, float yin): x{xin}, y{yin} {};
};

void drawSegment(Vec3f initialPoint, Vec3f finalPoint, TGAImage& image, frame frame)
{
	
	
	int numPoints = 20;
	float x0 = initialPoint.x;
	x0 = x0 * frame.width/2.0;

	float y0 = initialPoint.y;
	y0 = y0 * frame.height /2.0;

	float x1 = finalPoint.x;
	x1 = x1 * frame.width/2.0;

	float y1 = finalPoint.y;
	y1 = y1* frame.height/2.0;

	
	float slope = (y1 - y0)/(x1 - x0);
	for(int t = 0; t<numPoints; t++)
	{
		float x = x0 + t*((x1-x0)/numPoints);
		float y = y0 + (x - x0)*slope;
		
		image.set(x, y, red);
	}
	
}