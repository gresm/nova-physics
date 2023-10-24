/*

  This file is a part of the Nova Physics Engine
  project and distributed under the MIT license.

  Copyright © Kadir Aksoy
  https://github.com/kadir014/nova-physics

*/

#include "example_base.h"


void setup(Example *example) {
    // Create grounds & bridge

    nv_Body *ground_left = nv_Rect_new(
        nv_BodyType_STATIC,
        NV_VEC2(10.0, 52.5),
        0.0,
        nv_Material_CONCRETE,
        30.0, 40.0
    );

    nv_Space_add(example->space, ground_left);

    int n = 17; // Parts of the bridge
    double width = 78.0 / (double)n; // Width of one part of the bridge
    double w2 = width / 2.0;

    for (size_t i = 0; i < n; i++) {
        nv_Body *bridge_part = nv_Rect_new(
            nv_BodyType_DYNAMIC,
            NV_VEC2(25.0 + w2 + i * width, 33.0),
            0.0,
            nv_Material_CONCRETE,
            width, 2.0
        );

        nv_Space_add(example->space, bridge_part);
    }

    nv_Body *ground_right = nv_Rect_new(
        nv_BodyType_STATIC,
        NV_VEC2(118.0, 52.5),
        0.0,
        nv_Material_CONCRETE,
        30.0, 40.0
    );

    nv_Space_add(example->space, ground_right);


    // Link bridge parts with distance joint constraints
    for (size_t i = 1; i < n + 2; i++) {
        nv_Vector2 anchor_a;
        nv_Vector2 anchor_b;

        // Offset anchors by a tiny amount so they don't intersect
        double offset = w2 / 3.0;
        
        // Link to left ground
        if (i == 1) {
            anchor_a = NV_VEC2(15.0, -20.0);
            anchor_b = NV_VEC2(-w2, 0.0);
            offset /= 2.0;
        }
        // Link to right ground
        else if (i == n + 1) {
            anchor_a = NV_VEC2(w2, 0.0);
            anchor_b = NV_VEC2(-15, -20.0);
            offset /= 2.0;
        }
        // Link between bridge parts
        else {
            anchor_a = NV_VEC2(w2 - offset, 0.0);
            anchor_b = NV_VEC2(-w2 + offset, 0.0);
        }

        nv_Body *a = (nv_Body *)example->space->bodies->data[i];
        nv_Body *b = (nv_Body *)example->space->bodies->data[i + 1];

        nv_Constraint *dist_joint = nv_DistanceJoint_new(
            a, b,
            anchor_a, anchor_b,
            offset * 2.0 + 0.25
        );

        nv_Space_add_constraint(example->space, dist_joint);
    }

    //Create boxes on top of the bridge
    for (size_t i = 0; i < 8; i++) {
        nv_Body *box = nv_Rect_new(
            nv_BodyType_DYNAMIC,
            NV_VEC2(35.0 + i * 5.0, 23.0),
            0.0,
            nv_Material_WOOD,
            5.0, 5.0
        );

        nv_Space_add(example->space, box);
    }
}


int main(int argc, char *argv[]) {
    // Create example
    Example *example = Example_new(
        1280, 720,
        "Nova Physics  -  Bridge Example",
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