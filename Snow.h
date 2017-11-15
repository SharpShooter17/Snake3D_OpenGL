#ifndef SNOW_H_INCLUDED
#define SNOW_H_INCLUDED

#include <StopWatch.h>

class cSnow
{
private:

    float X;
    float Y;
    float Z;
    float Speed;
    float bottom;

    CStopWatch Timer;
    float TimeToFly = 0.5;
    float LeftTime = 0;
    unsigned int *texture;

    void Fly();
    void Draw();

    bool bCzyUpadlem;
public:
    cSnow(float maxX,
         float minX,
         float maxY,
         float minY,
         float maxZ,
         float minZ,
         unsigned int *text);
    ~cSnow();

    bool Control();
};

#endif // SNOW_H_INCLUDED
