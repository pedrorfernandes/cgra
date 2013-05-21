#ifndef _SKYBOX_H
#define _SKYBOX_H

#include "CGFobject.h"
#include "CGFappearance.h"

class SkyBox: public CGFobject {
private:
    CGFappearance * skyFront;
    CGFappearance * skyBack;
    CGFappearance * skyLeft;
    CGFappearance * skyRight;
    CGFappearance * skyTop;
    CGFappearance * skyBottom;
public:
    SkyBox();
    void draw();
};

#endif
