#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"

class ExampleObject: public CGFobject {
	public:
		void draw();
};

class MyUnitCube : public CGFobject {
    public:
        void draw();
};

class MyTable : public CGFobject {
public:
    void draw();
private:
    MyUnitCube myCube;
};


#endif