/*

  This file is a part of the Nova Physics Engine
  project and distributed under the MIT license.

  Copyright © Kadir Aksoy
  https://github.com/kadir014/nova-physics

*/

#include "example_base.h"


void setup(Example *example) {
    //Create ground & walls
    nv_Body *ground = nv_Rect_new(
        nv_BodyType_STATIC,
        NV_VEC2(64.0, 70.0),
        0.0,
        nv_Material_CONCRETE,
        128.0, 5.0
    );

    nv_Space_add(example->space, ground);

    // Create stacked boxes

    int cols = 20; // Columns of the stack
    int rows = 20; // Rows of the stack
    nv_float size = 3.0; // Size of the boxes
    nv_float s2 = size / 2.0;
    nv_float random_offset = 1.1; // Random horizontal offset magnitude

    for (size_t y = 0; y < rows; y++) {
    
        nv_float offset = 0;
        if (random_offset > 0.0)
            offset = frand(-random_offset / 2.0, random_offset / 2.0);

        for (size_t x = 0; x < cols; x ++) {

            nv_Body *box = nv_Rect_new(
                nv_BodyType_DYNAMIC,
                NV_VEC2(
                    example->width / 20.0 - ((nv_float)cols * size) / 2.0 + s2 + size * x,
                    70 - 2.5 - s2 - y * (size + 0.2)
                ),
                0.0,
                nv_Material_BASIC,
                size, size
            );

            nv_Space_add(example->space, box);
        }
    }
}


int main(int argc, char *argv[]) {
    // Create example
    Example *example = Example_new(
        1280, 720,
        "Nova Physics — Stacking Example",
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