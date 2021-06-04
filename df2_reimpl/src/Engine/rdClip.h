#ifndef _RDCLIP_H
#define _RDCLIP_H

#include "rdCanvas.h"
#include "Primitives/rdVector.h"

#define rdClip_Line2_ADDR (0x0046D6F0)
#define rdClip_CalcOutcode2_ADDR (0x0046DA10)
#define rdClip_Point3_ADDR (0x0046DA50)
#define rdClip_Line3Project_ADDR (0x0046DB10)
#define rdClip_Line3Ortho_ADDR (0x0046E480)
#define rdClip_Line3_ADDR (0x0046E9D0)
#define rdClip_Face3W_ADDR (0x0046EAF0)
#define rdClip_Face3WOrtho_ADDR (0x0046F420)
#define rdClip_Face3S_ADDR (0x0046FAE0)
#define rdClip_Face3SOrtho_ADDR (0x00470410)
#define rdClip_Face3GS_ADDR (0x00470AD0)
#define rdClip_Face3GSOrtho_ADDR (0x004716F0)
#define rdClip_Face3T_ADDR (0x00472090)
#define rdClip_Face3TOrtho_ADDR (0x00472DC0)
#define rdClip_Face3GT_ADDR (0x00473880)
#define rdClip_Face3GTOrtho_ADDR (0x004748D0)
#define rdClip_SphereInFrustrum_ADDR (0x004756E0)

#define rdClip_faceStatus (*(int*)0x0082EE5C)
#define pSourceVert (*(rdVector3**)0x0082EC50)
#define workIVerts ((float*)0x0082EC58) // 32
#define workVerts ((rdVector3*)0x0082ECD8) // 32
#define pDestVert (*(rdVector3**)0x0082EB44)
#define pDestIVert (*(float**)0x0082EB48)
#define workTVerts ((rdVector2*)0x0082EB50)
#define pSourceTVert (*(rdVector2**)0x0082EB3C)
#define pDestTVert (*(rdVector2**)0x0082EB40)

typedef struct rdClipFrustum rdClipFrustum;

enum CLIP_OUTCODE
{
    CLIP_LEFT = 0x1,
    CLIP_RIGHT = 0x10,
    CLIP_BOTTOM = 0x100,
    CLIP_TOP = 0x1000
};

int rdClip_Line2(rdCanvas *canvas, signed int *pX1, signed int *pY1, signed int *pX2, signed int *pY2);
int rdClip_CalcOutcode2(rdCanvas *canvas, int x, int y);
int rdClip_Point3(rdClipFrustum *clipFrustum, rdVector3 *point);
int rdClip_Line3Project(rdClipFrustum *clipFrustum, rdVector3 *point1, rdVector3 *point2, int *out1, int *out2);
int rdClip_Line3Ortho(rdClipFrustum *clipFrustum, rdVector3 *point1, rdVector3 *point2, int *out1, int *out2);
int rdClip_Line3(rdClipFrustum *clipFrustum, rdVector3 *point1, rdVector3 *point2, rdVector3 *pointOut1, rdVector3 *pointOut2, int *out1, int *out2);

int rdClip_SphereInFrustrum(rdClipFrustum *frust, rdVector3 *pos, float rad);

int rdClip_Face3W(rdClipFrustum *frustum, rdVector3 *vertices, int numVertices);

//static int (__cdecl *rdClip_SphereInFrustrum)(rdClipFrustum *frust, rdVector3 *pos, float rad) = (void*)rdClip_SphereInFrustrum_ADDR;
static int (*rdClip_Face3SOrtho)(rdClipFrustum *frustum, rdVector3 *vertices, int numVertices) = (void*)rdClip_Face3SOrtho_ADDR;
static int (*rdClip_Face3S)(rdClipFrustum *frustum, rdVector3 *vertices, int numVertices) = (void*)rdClip_Face3S_ADDR;
static int (*rdClip_Face3WOrtho)(rdClipFrustum *frustum, rdVector3 *vertices, int numVertices) = (void*)rdClip_Face3WOrtho_ADDR;
//static int (*rdClip_Face3W)(rdClipFrustum *frustum, rdVector3 *vertices, int numVertices) = (void*)rdClip_Face3W_ADDR;
static int (*rdClip_Face3GSOrtho)(rdClipFrustum *frustum, rdVector3 *vertices, float *a3, int numVertices) = (void*)rdClip_Face3GSOrtho_ADDR;
static int (*rdClip_Face3GS)(rdClipFrustum *frustum, rdVector3 *vertices, float *a3, int numVertices) = (void*)rdClip_Face3GS_ADDR;
static int (*rdClip_Face3TOrtho)(rdClipFrustum *frustum, rdVector3 *vertices, rdVector2 *uvs, int numVertices) = (void*)rdClip_Face3TOrtho_ADDR;
static int (*rdClip_Face3T)(rdClipFrustum *frustum, rdVector3 *vertices, rdVector2 *uvs, int numVertices) = (void*)rdClip_Face3T_ADDR;
static int (*rdClip_Face3GTOrtho)(rdClipFrustum *frustum, rdVector3 *vertices, rdVector2 *uvs, float *a4, int numVertices) = (void*)rdClip_Face3GTOrtho_ADDR;
static int (*rdClip_Face3GT)(rdClipFrustum *frustum, rdVector3 *vertices, rdVector2 *uvs, float *a4, int numVertices) = (void*)rdClip_Face3GT_ADDR;

#endif // _RDCLIP_H
