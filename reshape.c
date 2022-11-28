#ifndef RESHAPE
#define RESHAPE

#include <math.h>
#include "opengl.h"

void reshape (int w, int h)
{
 
   float *mper = (float*) malloc(16*sizeof(float)); 
 
   float l, r, b, t, n, f, aspect, fovy;
   l = -1.5; r=1.5; b=-1.0; t=1.0;
   n = 2.0; f=10.0;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
  // glOrtho   (-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);
  // glFrustum ( l, r, b, t, n, f);
 
  // aspect = (r-l)/(t-b);
  // fovy = 180* (2*atan(((t-b)/2)/fabs(n))) / acos(-1.0); 
  // gluPerspective ( (double) fovy, (double) aspect, (double) n, (double) f); 
 
 
   *(mper+0) = 2*fabs(n)/(r-l);
   *(mper+1) = 0.0;
   *(mper+2) = (r+l)/(r-l);
   *(mper+3) = 0.0;
   
   *(mper+4) = 0.0;
   *(mper+5) = 2*fabs(n)/(t-b);
   *(mper+6) = (t+b)/(t-b);
   *(mper+7) = 0.0;
  
   *(mper+8) = 0.0;
   *(mper+9) = 0.0;
   *(mper+10) = (fabs(n)+fabs(f))/(fabs(n)-fabs(f));
   *(mper+11) = 2*fabs(f)*fabs(n)/(fabs(n)-fabs(f));
     
   *(mper+12) = 0.0;
   *(mper+13) = 0.0;
   *(mper+14) = -1.0;
   *(mper+15) = 0.0;

 
   glMultTransposeMatrixf(mper); 
//   glMultMatrixf(mper); 
   glMatrixMode (GL_MODELVIEW);
}

#endif
