#include "IR_reader.h"
task main()
{
int angle_a = dirDC_A*20;//convert ir reading into degrees
int angle_b = dirDC_B*20;//convert ir reading into degrees
int distance;
#define length 18

//Formula from wikipedia (http://en.wikipedia.org/wiki/Triangulation):
distance = (1/(sin(angle_a+angle_b))/(length*sin(angle_a)*sin(angle_b)));
//which is derived from l = (d/tan(a))+(d/tan(b))
displayDrawTextLineVarArgs(distance)//I think this is the nxt screen display text function
}
