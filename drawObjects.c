#ifndef DRAWOBJECTS
#define DRAWOBJECTS

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"

void drawObjects( struct box *face )
{
    
    glPushMatrix();
    glTranslatef(0.0,2.0,0.0);
    drawBox( face );
    glColor3ub(200,10,100);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCone(1.0,3.0,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,-2.0,0.0);
    drawBox( face );
    glColor3ub(200,10,100);
    glTranslatef(0.0,0.0,1.0);
    glutSolidSphere(1.0,50,50);
    glPopMatrix();
    glPopMatrix();

}

#endif
