#include "../../wawata/components/object.hpp"
#include "../../wawata/components/texture.hpp"

namespace wawata
{
    namespace modules
    {
        struct actor;
    }
}

struct wawata::modules::actor
{
    float position[3] = {0.0, 0.0, 0.0};
    float rotation[3] = {0.0, 0.0, 0.0};
    float scale[3] = {0.0, 0.0, 0.0};

    std::vector<wawata::components::object> objects;
    std::vector<wawata::components::texture> textures;

    void draw();
};
