#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tvs_4_0 /D __EFFEKSEER_BUILD_VERSION16__=1 /EVS /Fh
//    Shader/EffekseerRenderer.ModelRenderer.ShaderTexture_VS.h
//    Shader/model_renderer_texture_VS.fx
//
//
// Buffer Definitions: 
//
// cbuffer VS_ConstantBuffer
// {
//
//   float4x4 mCameraProj;              // Offset:    0 Size:    64
//   float4x4 mModel;                   // Offset:   64 Size:    64
//   float4 fUV;                        // Offset:  128 Size:    16
//   float4 fAlphaUV;                   // Offset:  144 Size:    16
//   float4 fUVDistortionUV;            // Offset:  160 Size:    16
//   float4 fFlipbookParameter;         // Offset:  176 Size:    16
//   float4 fFlipbookIndexAndNextRate;  // Offset:  192 Size:    16
//   float4 fModelAlphaThreshold;       // Offset:  208 Size:    16
//   float4 fModelColor;                // Offset:  224 Size:    16
//   float4 fLightDirection;            // Offset:  240 Size:    16 [unused]
//   float4 fLightColor;                // Offset:  256 Size:    16 [unused]
//   float4 fLightAmbient;              // Offset:  272 Size:    16 [unused]
//   float4 mUVInversed;                // Offset:  288 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// VS_ConstantBuffer                 cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xyz         0     NONE  float   xyz 
// NORMAL                   0   xyz         1     NONE  float       
// NORMAL                   1   xyz         2     NONE  float       
// NORMAL                   2   xyz         3     NONE  float       
// TEXCOORD                 0   xy          4     NONE  float   xy  
// NORMAL                   3   xyzw        5     NONE  float   xyzw
// BLENDINDICES             0   xyzw        6     NONE   uint       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float   xyzw
// TEXCOORD                 0   xy          1     NONE  float   xy  
// TEXCOORD                 1     zw        1     NONE  float     zw
// TEXCOORD                 2   xy          2     NONE  float   xy  
// TEXCOORD                 3     z         2     NONE  float     z 
// TEXCOORD                 4   xy          3     NONE  float   xy  
// TEXCOORD                 5     z         3     NONE  float     z 
// COLOR                    0   xyzw        4     NONE  float   xyzw
//
vs_4_0
dcl_constantbuffer cb0[19], immediateIndexed
dcl_input v0.xyz
dcl_input v4.xy
dcl_input v5.xyzw
dcl_output_siv o0.xyzw, position
dcl_output o1.xy
dcl_output o1.zw
dcl_output o2.xy
dcl_output o2.z
dcl_output o3.xy
dcl_output o3.z
dcl_output o4.xyzw
dcl_temps 6
mul o4.xyzw, v5.xyzw, cb0[14].xyzw
mul r0.xyzw, v0.yyyy, cb0[5].xyzw
mad r0.xyzw, cb0[4].xyzw, v0.xxxx, r0.xyzw
mad r0.xyzw, cb0[6].xyzw, v0.zzzz, r0.xyzw
add r0.xyzw, r0.xyzw, cb0[7].xyzw
mul r1.xyzw, r0.yyyy, cb0[1].xyzw
mad r1.xyzw, cb0[0].xyzw, r0.xxxx, r1.xyzw
mad r1.xyzw, cb0[2].xyzw, r0.zzzz, r1.xyzw
mad o0.xyzw, cb0[3].xyzw, r0.wwww, r1.xyzw
mad r0.xy, v4.xyxx, cb0[8].zwzz, cb0[8].xyxx
mad r0.zw, v4.xxxy, cb0[9].zzzw, cb0[9].xxxy
mad o2.x, v4.x, cb0[10].z, cb0[10].x
mad r1.x, v4.y, cb0[10].w, cb0[10].y
lt r1.y, l(0.000000), cb0[11].x
if_nz r1.y
  frc o2.z, cb0[12].x
  round_ni r2.x, cb0[12].x
  add r1.y, r2.x, l(1.000000)
  mul r1.z, cb0[11].w, cb0[11].z
  eq r1.w, cb0[11].y, l(0.000000)
  if_nz r1.w
    ge r1.w, r1.y, r1.z
    mad r2.w, cb0[11].z, cb0[11].w, l(-1.000000)
    add r2.y, r2.x, l(1.000000)
    movc r2.yw, r1.wwww, r2.wwww, r2.xxxy
  else 
    eq r1.w, cb0[11].y, l(1.000000)
    if_nz r1.w
      mul r1.w, r1.z, r2.x
      ge r1.w, r1.w, -r1.w
      movc r1.w, r1.w, r1.z, -r1.z
      div r3.x, l(1.000000, 1.000000, 1.000000, 1.000000), r1.w
      mul r3.x, r2.x, r3.x
      frc r3.x, r3.x
      mul r2.y, r1.w, r3.x
      mul r1.w, r1.z, r1.y
      ge r1.w, r1.w, -r1.w
      movc r1.w, r1.w, r1.z, -r1.z
      div r3.x, l(1.000000, 1.000000, 1.000000, 1.000000), r1.w
      mul r3.x, r1.y, r3.x
      frc r3.x, r3.x
      mul r2.w, r1.w, r3.x
    else 
      eq r1.w, cb0[11].y, l(2.000000)
      div r3.x, r2.x, r1.z
      round_ni r3.x, r3.x
      add r3.y, r3.x, r3.x
      ge r3.y, r3.y, -r3.y
      movc r3.yz, r3.yyyy, l(0,2.000000,0.500000,0), l(0,-2.000000,-0.500000,0)
      mul r3.x, r3.z, r3.x
      frc r3.x, r3.x
      mul r3.x, r3.x, r3.y
      eq r3.x, r3.x, l(1.000000)
      mul r3.y, r1.z, r2.x
      ge r3.y, r3.y, -r3.y
      movc r3.y, r3.y, r1.z, -r1.z
      div r3.z, l(1.000000, 1.000000, 1.000000, 1.000000), r3.y
      mul r3.z, r2.x, r3.z
      frc r3.z, r3.z
      mul r3.y, r3.z, r3.y
      mad r3.z, cb0[11].z, cb0[11].w, l(-1.000000)
      round_ni r3.w, r3.y
      add r3.w, -r3.w, r3.z
      movc r3.x, r3.x, r3.w, r3.y
      div r3.w, r1.y, r1.z
      round_ni r3.w, r3.w
      add r4.x, r3.w, r3.w
      ge r4.x, r4.x, -r4.x
      movc r4.xy, r4.xxxx, l(2.000000,0.500000,0,0), l(-2.000000,-0.500000,0,0)
      mul r3.w, r3.w, r4.y
      frc r3.w, r3.w
      mul r3.w, r3.w, r4.x
      eq r3.w, r3.w, l(1.000000)
      mul r4.x, r1.z, r1.y
      ge r4.x, r4.x, -r4.x
      movc r1.z, r4.x, r1.z, -r1.z
      div r4.x, l(1.000000, 1.000000, 1.000000, 1.000000), r1.z
      mul r1.y, r1.y, r4.x
      frc r1.y, r1.y
      mul r1.y, r1.y, r1.z
      round_ni r1.z, r1.y
      add r1.z, -r1.z, r3.z
      movc r3.y, r3.w, r1.z, r1.y
      add r2.z, r2.x, l(1.000000)
      movc r2.yw, r1.wwww, r3.xxxy, r2.xxxz
    endif 
  endif 
  ftoi r1.yz, r2.yywy
  ftoi r1.w, cb0[11].z
  and r2.xy, r1.yzyy, l(0x80000000, 0x80000000, 0, 0)
  imax r2.zw, r1.yyyz, -r1.yyyz
  imax r3.x, r1.w, -r1.w
  udiv r4.x, r5.x, r2.z, r3.x
  ineg r2.z, r5.x
  movc r2.x, r2.x, r2.z, r5.x
  itof r5.x, r2.x
  xor r1.yz, r1.wwww, r1.yyzy
  ineg r1.w, r4.x
  and r1.yz, r1.yyzy, l(0, 0x80000000, 0x80000000, 0)
  movc r1.y, r1.y, r1.w, r4.x
  itof r5.y, r1.y
  div r1.yw, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[11].zzzw
  mad r2.xz, -r5.xxyx, r1.yywy, r0.xxyx
  mul r2.xz, r2.xxzx, cb0[11].zzwz
  udiv r3.x, r4.x, r2.w, r3.x
  ineg r2.w, r4.x
  movc r2.y, r2.y, r2.w, r4.x
  itof r4.x, r2.y
  ineg r2.y, r3.x
  movc r1.z, r1.z, r2.y, r3.x
  itof r4.y, r1.z
  mul r2.yw, r1.yyyw, r4.xxxy
  mad r2.xy, r2.xzxx, r1.ywyy, r2.ywyy
else 
  mov r2.xy, l(0,0,0,0)
  mov o2.z, l(0)
endif 
mad o1.y, cb0[18].y, r0.y, cb0[18].x
mad o1.w, cb0[18].y, r0.w, cb0[18].x
mad o2.y, cb0[18].y, r1.x, cb0[18].x
mov o1.xz, r0.xxzx
mov r2.z, cb0[13].x
mov o3.xyz, r2.xyzx
ret 
// Approximately 124 instruction slots used
#endif

const BYTE g_VS[] =
{
     68,  88,  66,  67,  81,  75, 
    246,  71, 249, 130, 184,  72, 
    161, 250, 191, 220,  75,  38, 
    152,  26,   1,   0,   0,   0, 
    156,  20,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     92,   3,   0,   0,  60,   4, 
      0,   0,  40,   5,   0,   0, 
     32,  20,   0,   0,  82,  68, 
     69,  70,  32,   3,   0,   0, 
      1,   0,   0,   0,  80,   0, 
      0,   0,   1,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    254, 255,  16,   1,   0,   0, 
    238,   2,   0,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     86,  83,  95,  67, 111, 110, 
    115, 116,  97, 110, 116,  66, 
    117, 102, 102, 101, 114,   0, 
    171, 171,  60,   0,   0,   0, 
     13,   0,   0,   0, 104,   0, 
      0,   0,  48,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 160,   1,   0,   0, 
      0,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    172,   1,   0,   0,   0,   0, 
      0,   0, 188,   1,   0,   0, 
     64,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    196,   1,   0,   0,   0,   0, 
      0,   0, 212,   1,   0,   0, 
    128,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    216,   1,   0,   0,   0,   0, 
      0,   0, 232,   1,   0,   0, 
    144,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    244,   1,   0,   0,   0,   0, 
      0,   0,   4,   2,   0,   0, 
    160,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
     20,   2,   0,   0,   0,   0, 
      0,   0,  36,   2,   0,   0, 
    176,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
     56,   2,   0,   0,   0,   0, 
      0,   0,  72,   2,   0,   0, 
    192,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   2,   0,   0,   0,   0, 
      0,   0, 116,   2,   0,   0, 
    208,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    140,   2,   0,   0,   0,   0, 
      0,   0, 156,   2,   0,   0, 
    224,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    168,   2,   0,   0,   0,   0, 
      0,   0, 184,   2,   0,   0, 
    240,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
     56,   2,   0,   0,   0,   0, 
      0,   0, 200,   2,   0,   0, 
      0,   1,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
     56,   2,   0,   0,   0,   0, 
      0,   0, 212,   2,   0,   0, 
     16,   1,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
     56,   2,   0,   0,   0,   0, 
      0,   0, 226,   2,   0,   0, 
     32,   1,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
     56,   2,   0,   0,   0,   0, 
      0,   0, 109,  67,  97, 109, 
    101, 114,  97,  80, 114, 111, 
    106,   0,   3,   0,   3,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    109,  77, 111, 100, 101, 108, 
      0, 171,   3,   0,   3,   0, 
      4,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  85,  86,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 102,  65, 108, 112, 
    104,  97,  85,  86,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  85,  86,  68, 105, 115, 
    116, 111, 114, 116, 105, 111, 
    110,  85,  86,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 102,  70, 108, 105, 
    112,  98, 111, 111, 107,  80, 
     97, 114,  97, 109, 101, 116, 
    101, 114,   0, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 102,  70, 108, 105, 
    112,  98, 111, 111, 107,  73, 
    110, 100, 101, 120,  65, 110, 
    100,  78, 101, 120, 116,  82, 
     97, 116, 101,   0, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 102,  77, 
    111, 100, 101, 108,  65, 108, 
    112, 104,  97,  84, 104, 114, 
    101, 115, 104, 111, 108, 100, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 102,  77, 111, 100, 
    101, 108,  67, 111, 108, 111, 
    114,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  76, 105, 103, 104, 116, 
     68, 105, 114, 101,  99, 116, 
    105, 111, 110,   0, 102,  76, 
    105, 103, 104, 116,  67, 111, 
    108, 111, 114,   0, 102,  76, 
    105, 103, 104, 116,  65, 109, 
     98, 105, 101, 110, 116,   0, 
    109,  85,  86,  73, 110, 118, 
    101, 114, 115, 101, 100,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  57, 
     46,  50,  57,  46,  57,  53, 
     50,  46,  51,  49,  49,  49, 
      0, 171,  73,  83,  71,  78, 
    216,   0,   0,   0,   7,   0, 
      0,   0,   8,   0,   0,   0, 
    176,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   7,   0,   0, 
    185,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   0,   0,   0, 
    185,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   7,   0,   0,   0, 
    185,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
    192,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   3,   3,   0,   0, 
    185,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,  15,  15,   0,   0, 
    201,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   6,   0, 
      0,   0,  15,   0,   0,   0, 
     80,  79,  83,  73,  84,  73, 
     79,  78,   0,  78,  79,  82, 
     77,  65,  76,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  66,  76,  69,  78,  68, 
     73,  78,  68,  73,  67,  69, 
     83,   0, 171, 171,  79,  83, 
     71,  78, 228,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0, 200,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0, 212,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,   3,  12, 
      0,   0, 212,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  12,   3, 
      0,   0, 212,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,  12, 
      0,   0, 212,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   4,  11, 
      0,   0, 212,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   3,  12, 
      0,   0, 212,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   4,  11, 
      0,   0, 221,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  67, 
     79,  76,  79,  82,   0, 171, 
     83,  72,  68,  82, 240,  14, 
      0,   0,  64,   0,   1,   0, 
    188,   3,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,  19,   0, 
      0,   0,  95,   0,   0,   3, 
    114,  16,  16,   0,   0,   0, 
      0,   0,  95,   0,   0,   3, 
     50,  16,  16,   0,   4,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   5,   0, 
      0,   0, 103,   0,   0,   4, 
    242,  32,  16,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    101,   0,   0,   3,  50,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 194,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3,  50,  32, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3,  66,  32, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3,  50,  32, 
     16,   0,   3,   0,   0,   0, 
    101,   0,   0,   3,  66,  32, 
     16,   0,   3,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   4,   0,   0,   0, 
    104,   0,   0,   2,   6,   0, 
      0,   0,  56,   0,   0,   8, 
    242,  32,  16,   0,   4,   0, 
      0,   0,  70,  30,  16,   0, 
      5,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     14,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      0,   0,   0,   0,  86,  21, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      6,  16,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      6,   0,   0,   0, 166,  26, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      1,   0,   0,   0,  86,   5, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0, 166,  10, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  11,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   4,   0, 
      0,   0, 230, 138,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  70, 128,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  50,   0,   0,  11, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   6,  20,  16,   0, 
      4,   0,   0,   0, 166, 142, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,   6, 132, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  50,   0, 
      0,  11,  18,  32,  16,   0, 
      2,   0,   0,   0,  10,  16, 
     16,   0,   4,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
     50,   0,   0,  11,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     26,  16,  16,   0,   4,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,  10,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,  10,   0, 
      0,   0,  49,   0,   0,   8, 
     34,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,  31,   0, 
      4,   3,  26,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
      0,   6,  66,  32,  16,   0, 
      2,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     12,   0,   0,   0,  65,   0, 
      0,   6,  18,   0,  16,   0, 
      2,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     12,   0,   0,   0,   0,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  56,   0,   0,   9, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  24,   0,   0,   8, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      4,   3,  58,   0,  16,   0, 
      1,   0,   0,   0,  29,   0, 
      0,   7, 130,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  11, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128, 191,   0,   0, 
      0,   7,  34,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  55,   0,   0,   9, 
    162,   0,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   2,   0,   0,   0, 
      6,   4,  16,   0,   2,   0, 
      0,   0,  18,   0,   0,   1, 
     24,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,  11,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  31,   0,   4,   3, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     29,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  55,   0,   0,  10, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     14,   0,   0,  10,  18,   0, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,  58,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,   0,   5, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7,  34,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     29,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  55,   0,   0,  10, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     14,   0,   0,  10,  18,   0, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,  58,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,   0,   5, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  18,   0,   0,   1, 
     24,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,  11,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,  64,  14,   0,   0,   7, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     65,   0,   0,   5,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,   0,   0,   0,   7, 
     34,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     29,   0,   0,   8,  34,   0, 
     16,   0,   3,   0,   0,   0, 
     26,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16, 128, 
     65,   0,   0,   0,   3,   0, 
      0,   0,  55,   0,   0,  15, 
     98,   0,  16,   0,   3,   0, 
      0,   0,  86,   5,  16,   0, 
      3,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  63,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0, 192, 
      0,   0,   0, 191,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     26,   0,   0,   5,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   3,   0,   0,   0, 
     24,   0,   0,   7,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  56,   0, 
      0,   7,  34,   0,  16,   0, 
      3,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  29,   0,   0,   8, 
     34,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16, 128,  65,   0,   0,   0, 
      3,   0,   0,   0,  55,   0, 
      0,  10,  34,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   3,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  14,   0,   0,  10, 
     66,   0,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,  26,   0, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
      0,   5,  66,   0,  16,   0, 
      3,   0,   0,   0,  42,   0, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   3,   0,   0,   0, 
     42,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  11,  66,   0,  16,   0, 
      3,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,  58, 128, 
     32,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128, 191, 
     65,   0,   0,   5, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     26,   0,  16,   0,   3,   0, 
      0,   0,   0,   0,   0,   8, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   3,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  55,   0, 
      0,   9,  18,   0,  16,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      3,   0,   0,   0,  14,   0, 
      0,   7, 130,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  65,   0,   0,   5, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   7,  18,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  29,   0,   0,   8, 
     18,   0,  16,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  10,   0, 
     16, 128,  65,   0,   0,   0, 
      4,   0,   0,   0,  55,   0, 
      0,  15,  50,   0,  16,   0, 
      4,   0,   0,   0,   6,   0, 
     16,   0,   4,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,  64,   0,   0,   0,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0, 192,   0,   0, 
      0, 191,   0,   0,   0,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     26,   0,  16,   0,   4,   0, 
      0,   0,  26,   0,   0,   5, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   4,   0, 
      0,   0,  24,   0,   0,   7, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   4,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  29,   0, 
      0,   8,  18,   0,  16,   0, 
      4,   0,   0,   0,  10,   0, 
     16,   0,   4,   0,   0,   0, 
     10,   0,  16, 128,  65,   0, 
      0,   0,   4,   0,   0,   0, 
     55,   0,   0,  10,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  14,   0, 
      0,  10,  18,   0,  16,   0, 
      4,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   4,   0,   0,   0, 
     26,   0,   0,   5,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     65,   0,   0,   5,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,   8, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  55,   0, 
      0,   9,  34,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   7,  66,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  55,   0,   0,   9, 
    162,   0,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,   6,   4, 
     16,   0,   3,   0,   0,   0, 
      6,   8,  16,   0,   2,   0, 
      0,   0,  21,   0,   0,   1, 
     21,   0,   0,   1,  27,   0, 
      0,   5,  98,   0,  16,   0, 
      1,   0,   0,   0,  86,   7, 
     16,   0,   2,   0,   0,   0, 
     27,   0,   0,   6, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,  11,   0,   0,   0, 
      1,   0,   0,  10,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    150,   5,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0, 128,   0,   0, 
      0, 128,   0,   0,   0,   0, 
      0,   0,   0,   0,  36,   0, 
      0,   8, 194,   0,  16,   0, 
      2,   0,   0,   0,  86,   9, 
     16,   0,   1,   0,   0,   0, 
     86,   9,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     36,   0,   0,   8,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  78,   0,   0,   9, 
     18,   0,  16,   0,   4,   0, 
      0,   0,  18,   0,  16,   0, 
      5,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  40,   0,   0,   5, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      5,   0,   0,   0,  55,   0, 
      0,   9,  18,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      5,   0,   0,   0,  43,   0, 
      0,   5,  18,   0,  16,   0, 
      5,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     87,   0,   0,   7,  98,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  86,   6,  16,   0, 
      1,   0,   0,   0,  40,   0, 
      0,   5, 130,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   4,   0,   0,   0, 
      1,   0,   0,  10,  98,   0, 
     16,   0,   1,   0,   0,   0, 
     86,   6,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0, 128,   0,   0,   0, 128, 
      0,   0,   0,   0,  55,   0, 
      0,   9,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  43,   0, 
      0,   5,  34,   0,  16,   0, 
      5,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     14,   0,   0,  11, 162,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63, 166, 142,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  50,   0,   0,  10, 
     82,   0,  16,   0,   2,   0, 
      0,   0,   6,   1,  16, 128, 
     65,   0,   0,   0,   5,   0, 
      0,   0,  86,   7,  16,   0, 
      1,   0,   0,   0,   6,   1, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8,  82,   0, 
     16,   0,   2,   0,   0,   0, 
      6,   2,  16,   0,   2,   0, 
      0,   0, 166, 139,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  78,   0,   0,   9, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  18,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  40,   0,   0,   5, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  55,   0, 
      0,   9,  34,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  43,   0, 
      0,   5,  18,   0,  16,   0, 
      4,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     40,   0,   0,   5,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  55,   0,   0,   9, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  43,   0,   0,   5, 
     34,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 162,   0,  16,   0, 
      2,   0,   0,   0,  86,  13, 
     16,   0,   1,   0,   0,   0, 
      6,   4,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,   9, 
     50,   0,  16,   0,   2,   0, 
      0,   0, 134,   0,  16,   0, 
      2,   0,   0,   0, 214,   5, 
     16,   0,   1,   0,   0,   0, 
    214,   5,  16,   0,   2,   0, 
      0,   0,  18,   0,   0,   1, 
     54,   0,   0,   8,  50,   0, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
     66,  32,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   1,  50,   0,   0,  11, 
     34,  32,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,  18,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     18,   0,   0,   0,  50,   0, 
      0,  11, 130,  32,  16,   0, 
      1,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
     18,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,  18,   0,   0,   0, 
     50,   0,   0,  11,  34,  32, 
     16,   0,   2,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,  18,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,  18,   0, 
      0,   0,  54,   0,   0,   5, 
     82,  32,  16,   0,   1,   0, 
      0,   0,   6,   2,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   6,  66,   0,  16,   0, 
      2,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     13,   0,   0,   0,  54,   0, 
      0,   5, 114,  32,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
    124,   0,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,  62,   0, 
      0,   0,   6,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,  14,   0,   0,   0, 
     18,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
