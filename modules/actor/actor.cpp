#include "actor.hpp"
#include <algorithm>

void wawata::modules::actor::draw()
{
    //std::for_each(objects->begin(), objects->end(), [](int offset){objects[offset].draw()});

    // temporary solution
    for(int offset = 0; offset < objects.size(); offset++)
    {
        objects[offset].draw();
    }
}
