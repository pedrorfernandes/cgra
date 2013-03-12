#ifndef MY_CYLINDER
#define MY_CYLINDER

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

class myCylinder : public CGFobject {

	public:
		myCylinder(int slices, int stacks/*, bool smooth*/);

};



#endif
