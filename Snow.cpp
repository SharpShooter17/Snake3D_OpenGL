#include "Snow.h"
#include <ctime>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glext.h>

cSnow::cSnow(float maxX,
         float minX,
         float maxY,
         float minY,
         float maxZ,
         float minZ,
         unsigned int *text)
{
    srand(time(NULL));
    X = rand() % static_cast<int>(2*maxX) + minX;
    Y = (maxY);
    Z = rand() % static_cast<int>(2*maxZ) + minZ;

    bottom = 0;

    texture = text;

    TimeToFly = (rand() % 20) * 0.1;
    Speed = (rand() % 10) * 0.01;

    Timer.Reset();
    bCzyUpadlem = false;
}

cSnow::~cSnow()
{
}

void cSnow::Draw()
{
    glPointSize( 15.0 );
    glTexEnvf( GL_POINT_SPRITE_NV, GL_COORD_REPLACE_NV, GL_TRUE );
    glEnable( GL_POINT_SPRITE_NV );

    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER,0.9);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, *texture);

    glBegin(GL_POINTS);

    glVertex3f(X,Y,Z);

    glEnd();

    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glDisable( GL_POINT_SPRITE_NV );
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_TEXTURE_2D);
}

void cSnow::Fly()
{
    Y -= Speed;

    if (Y < bottom){
        bCzyUpadlem = true;
    }
}

bool cSnow::Control()
{
    LeftTime += Timer.GetElapsedSeconds();
    Timer.Reset();

    Draw();

    if( TimeToFly < LeftTime ){
        Fly();
        LeftTime = 0;
        return true;
    }
    if ( bCzyUpadlem )
        return false;

    return true;
}
