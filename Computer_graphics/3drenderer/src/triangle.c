#include "./headers/display.h"
#include "./headers/triangle.h"
#include "./headers/vector.h"



void i_swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void f_swap(float* a, float* b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

void fill_flat_top_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color){
   
    // find the two slopes (two legs of the triangle)
    float inv_slope_1 = (float)(x2 - x0) / (y2 - y0);
    float inv_slope_2 = (float)(x2 - x1) / (y2 - y1);

    // Start x_start and x_end from bottom vertex (x2, y2)
    float x_start = x2;
    float x_end = x2;
    // Loop all scanlines from top to bottom
    for (int y = y2; y >= y0; y--) {
        draw_line(x_start, y, x_end, y, color);
        x_start -= inv_slope_1;
        x_end -= inv_slope_2;

    }

}
void fill_flat_bottom_triangle(int x0, int y0, int x1, int y1,int x2, int y2, uint32_t color){
    
    // find the two slopes (two legs of the triangle)
	float inv_slope_1 = (float)(x1 - x0) / (y1 - y0);
	float inv_slope_2 = (float)(x2 - x0) / (y2 - y0);

    // Start x_start and x_end from top vertex (x0, y0)
     float x_start = x0;
     float x_end = x0;
    // Loop all scanlines from top to bottom
    for (int y = y0; y <= y2; y++) {
        draw_line(x_start, y, x_end, y, color);
        x_start += inv_slope_1;
        x_end   += inv_slope_2;

    }


}



void draw_filled_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color) {
    // we need to sort the vertices by y-coordinate ascending (y0 < y1 < y2)

    if (y0 > y1) {
        i_swap(&y0, &y1);
        i_swap(&x0, &x1);
    }
    if (y1 > y2) {
     i_swap(&y1, &y2);
     i_swap(&x1, &x2);
    } 
    if(y0 > y1) {
		i_swap(&y0, &y1);
		i_swap(&x0, &x1);
	}

    if (y1 == y2) {
        // simple draw a flat-bottom triangle
        fill_flat_bottom_triangle(x0, y0, x1, y1, x2, y2, color);
        
    }
    else if (y0 == y1) {
        // simple draw a flat-top triangle
        fill_flat_top_triangle(x0, y0, x1, y1, x2, y2, color);

    }
    else {

        // calculate the new vertex (Mx, My) using triangle similarity 
        int My = y1;
        int Mx = ((float)((x2 - x0) * (y1 - y0)) / (float)(y2 - y0)) + x0;

        // draw flat-bottom triangle 

        fill_flat_bottom_triangle(x0, y0, x1, y1, Mx, My, color);

        // draw flat-top triangle
        fill_flat_top_triangle(x1, y1, Mx, My, x2, y2, color);
    }


}

///////////////////////////////////////////////////////////////////////////////
vect3_t barycentric_weights(vect2_t a, vect2_t b, vect2_t c, vect2_t p) {
    // Find the vectors between the vertices ABC and point p
    vect2_t ac = vect2_sub(c, a);
    vect2_t ab = vect2_sub(b, a);
    vect2_t ap = vect2_sub(p, a);
    vect2_t pc = vect2_sub(c, p);
    vect2_t pb = vect2_sub(b, p);

    // Compute the area of the full parallegram/triangle ABC using 2D cross
    // product
    float area_parallelogram_abc = (ac.x * ab.y - ac.y * ab.x);  // || AC x AB ||

    // Alpha is the area of the small parallelogram/triangle PBC divided by the
    // area of the full parallelogram/triangle ABC
    float alpha = (pc.x * pb.y - pc.y * pb.x) / area_parallelogram_abc;

    // Beta is the area of the small parallelogram/triangle APC divided by the
    // area of the full parallelogram/triangle ABC
    float beta = (ac.x * ap.y - ac.y * ap.x) / area_parallelogram_abc;

    // Weight gamma is easily found since barycentric coordinates always add up
    // to 1.0
    float gamma = 1 - alpha - beta;

    vect3_t weights = { alpha, beta, gamma };
    return weights;
}
///////////////////////////////////////////////////////////////////////////////
// Function to draw the textured pixel at position x and y using interpolation
///////////////////////////////////////////////////////////////////////////////
void draw_texel(int x, int y, uint32_t* texture, vect2_t point_a, vect2_t point_b,
    vect2_t point_c, float u0, float v0, float u1, float v1,
    float u2, float v2) {
    vect2_t point_p = { x, y };
    vect3_t weights = barycentric_weights(point_a, point_b, point_c, point_p);

    float alpha = weights.x;
    float beta = weights.y;
    float gamma = weights.z;

    // Perform the interpolation of all U and V values using barycentric weights
    float interpolated_u = (u0)*alpha + (u1)*beta + (u2)*gamma;
    float interpolated_v = (v0)*alpha + (v1)*beta + (v2)*gamma;

    // Map the UV coordinate to the full texture width and height
    int tex_x = abs((int)(interpolated_u * texture_width));
    int tex_y = abs((int)(interpolated_v * texture_height));

    draw_pixel(x, y, texture[(texture_width * tex_y) + tex_x]);
}

void draw_texture_triangle(
    int x0, int y0, float u0, float v0,
    int x1, int y1, float u1, float v1,
    int x2, int y2, float u2, float v2, 
    uint32_t* texture
    ) {
    // We need to sort the vertices by y-coordinate ascending (y0 < y1 < y2)
    if (y0 > y1) {
        i_swap(&y0, &y1);
        i_swap(&x0, &x1);
        f_swap(&u0, &u1);
        f_swap(&v0, &v1);
    }
    if (y1 > y2) {
        i_swap(&y1, &y2);
        i_swap(&x1, &x2);
        f_swap(&u1, &u2);
        f_swap(&v1, &v2);
    }
    if (y0 > y1) {
        i_swap(&y0, &y1);
        i_swap(&x0, &x1);
        f_swap(&u0, &u1);
        f_swap(&v0, &v1);
    }

    // Create vector points and texture coords after we sort the vertices
    vect2_t point_a = { x0, y0 };
    vect2_t point_b = { x1, y1 };
    vect2_t point_c = { x2, y2 };

    ///////////////////////////////////////////////////////
    // Render the upper part of the triangle (flat-bottom)
    ///////////////////////////////////////////////////////
    float inv_slope_1 = 0;
    float inv_slope_2 = 0;

    if (y1 - y0 != 0) inv_slope_1 = (float)(x1 - x0) / abs(y1 - y0);
    if (y2 - y0 != 0) inv_slope_2 = (float)(x2 - x0) / abs(y2 - y0);

    if (y1 - y0 != 0) {
        for (int y = y0; y <= y1; y++) {
            int x_start = x1 + (y - y1) * inv_slope_1;
            int x_end = x0 + (y - y0) * inv_slope_2;

            if (x_end < x_start) {
                i_swap(&x_start, &x_end);  // swap if x_start is to the right of x_end
            }

            for (int x = x_start; x < x_end; x++) {
                // Draw our pixel with the color that comes from the texture
                draw_texel(x, y, texture, point_a, point_b, point_c, u0, v0, u1, v1, u2,
                    v2);
            }
        }
    }

    ///////////////////////////////////////////////////////
    // Render the bottom part of the triangle (flat-top)
    ///////////////////////////////////////////////////////
    inv_slope_1 = 0;
    inv_slope_2 = 0;

    if (y2 - y1 != 0) inv_slope_1 = (float)(x2 - x1) / abs(y2 - y1);
    if (y2 - y0 != 0) inv_slope_2 = (float)(x2 - x0) / abs(y2 - y0);

    if (y2 - y1 != 0) {
        for (int y = y1; y <= y2; y++) {
            int x_start = x1 + (y - y1) * inv_slope_1;
            int x_end = x0 + (y - y0) * inv_slope_2;

            if (x_end < x_start) {
                i_swap(&x_start, &x_end);  // swap if x_start is to the right of x_end
            }

            for (int x = x_start; x < x_end; x++) {
                // Draw our pixel with the color that comes from the texture
                draw_texel(x, y, texture, point_a, point_b, point_c, u0, v0, u1, v1, u2,
                    v2);
            }
        }
    }


}
