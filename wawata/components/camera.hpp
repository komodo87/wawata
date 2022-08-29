namespace wawata
{
    namespace components
    {
        struct camera;
    }
}

struct wawata::components::camera
{
    float position[3] = {0.0, 0.0, 0.0};
    float look_to[3] = {0.0, 0.0, 1.0};
    float fov = 45.0;
    float render_range[2] = {0.1, 100.0};
};
