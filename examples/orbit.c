/*

  This file is a part of the Nova Physics Engine
  project and distributed under the MIT license.

  Copyright © Kadir Aksoy
  https://github.com/kadir014/nova-physics

*/

#include "example_base.h"


void setup(Example *example) {
    // Set space gravity to 0
    example->space->gravity = nv_Vector2_zero;
    

    // Create planets & stars
    // also give planets some inital force

    nv_Material star_material = (nv_Material){
        .density = 15.0,
        .restitution = 0.5,
        .friction = 0.0
    };

    nv_Material planet_material = (nv_Material){
        .density = 2.0,
        .restitution = 0.5,
        .friction = 0.0
    };
    
    nv_Body *star = nv_Circle_new(
        nv_BodyType_DYNAMIC,
        NV_VEC2(64.0, 36.0),
        0.0,
        star_material,
        3.0
    );
    
    nv_Space_add(example->space, star);

    nv_Body_set_is_attractor(star, true);


    nv_Body *planet1 = nv_Circle_new(
        nv_BodyType_DYNAMIC,
        NV_VEC2(85.0, 28.0),
        0.0,
        planet_material,
        1.5
    );

    nv_Space_add(example->space, planet1);

    nv_Body_apply_force(planet1, NV_VEC2(0.0, 8.0e3));


    nv_Body *planet2 = nv_Circle_new(
        nv_BodyType_DYNAMIC,
        NV_VEC2(30.0, 35.0),
        0.0,
        planet_material,
        1.5
    );

    nv_Space_add(example->space, planet2);

    nv_Body_apply_force(planet2, NV_VEC2(0.0, 8.0e3));


    nv_Body *planet3 = nv_Rect_new(
        nv_BodyType_DYNAMIC,
        NV_VEC2(30.0, 55.0),
        0.0,
        planet_material,
        3.1, 2.1
    );

    nv_Space_add(example->space, planet3);

    nv_Body_apply_force(planet3, NV_VEC2(3.6e3, 5.0e3));
}


int main(int argc, char *argv[]) {
    // Create example
    Example *example = Example_new(
        1280, 720,
        "Nova Physics  -  Orbit Example",
        165.0,
        1.0/60.0,
        ExampleTheme_DARK
    );

    // Set callbacks
    example->setup_callback = setup;

    // Run the example
    Example_run(example);

    // Free the space allocated by example
    Example_free(example);

    return 0;
}