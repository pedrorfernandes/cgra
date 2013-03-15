#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"
#include <math.h>
#include <vector>

#define PI 3.14159265359
using namespace std;

class myCylinder : public CGFobject {

	int slices;
	int stacks;
	vector<float> xPoints;
	vector<float> yPoints;
	vector<float> zPoints;
	vector<float> norms;

	public:
		myCylinder(int slices, int stacks/*, bool smooth*/);
		void draw();
		float norm(float x, float y, float z);

};



#endif
