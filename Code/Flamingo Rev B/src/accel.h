#ifndef ACCEL_H
#define ACCEL_H

///// legacy
void initAccelOffset(void);
float getOffsetAccel(float gfactor);
/////

void initPhyisicalOffsetAccelY(void);

float getPhysicalOffsetAccelY(void);

float getPhysicalAccelY(void);

float getNormalizedAccelY(void);

float getNormalizedOffsetAccelY(void);






#endif
