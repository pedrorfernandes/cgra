#include "MyClock.h"

MyClock::MyClock(): cylinder(CLOCK_SLICES, CLOCK_STACKS, true) {
    clockAppearance = new CGFappearance("clock.png", GL_CLAMP, GL_CLAMP);
    cylinder.setTextureAtBase(true);
}

void MyClock::draw() {
    clockAppearance->apply();
    cylinder.draw();
}