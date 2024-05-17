
#ifndef GLOBALHEADERS_H
#define GLOBALHEADERS_H

#include "./vector.h"
#include "./display.h"

extern bool is_running;

// Function Prototypes/Declarations
void setup(void);
void update(void);
void render(void);
void process_input(void);
vect2_t project(vect3_t point);


#endif // !


