static const GLfloat kBt601VideoRangeYUV2RGBMatrix[] = {
    1.164384,  1.164384, 1.164384,
    0.0,   -0.391762, 2.017232,
    1.596027, -0.812968, 0.0,
};

static const GLfloat kBt601FullRangeYUV2RGBMatrix[] = {
    1.0, 1.0, 1.0,
    0.0, -0.344136, 1.772,
    1.402, -0.714136, 0.0,
};

static const GLfloat kBt709VideoRangeYUV2RGBMatrix[] = {
    1.164384,  1.164384,  1.164384,
    0.0,   -0.213249,  2.112402,
    1.792741, -0.532909,  0.0,
};

static const GLfloat kBt709FullRangeYUV2RGBMatrix[] = {
    1.0,  1.0,  1.0,
    0.0,   -0.187324,  1.8556,
    1.5748, -0.468124,  0.0,
};

static const GLfloat kBt2020VideoRangeYUV2RGBMatrix[] = {
    1.164384,  1.164384,  1.164384,
    0.0,   -0.187326,  2.141772,
    1.678674, -0.650424,  0.0,
};

static const GLfloat kBt2020FullRangeYUV2RGBMatrix[] = {
    1.0,  1.0,  1.0,
    0.0,   -0.164553,  1.8814,
    1.4746, -0.571353,  0.0,
};

static const char* kGlvsYuv420pToRgb =
    "    // Vertex Shader                                                                \n"
    "    precision highp float;                                                           \n"
    "    attribute highp vec4 a_position;                                                      \n"
    "    attribute highp vec2 a_texCoord0;                                                     \n"
    "    varying highp vec2 v_texCoord0;                                                       \n"
    "    void main(void)                                                                 \n"
    "    {                                                                               \n"
    "        gl_Position = a_position;                                                   \n"
    "        v_texCoord0 = vec2(a_texCoord0.x,1.0-a_texCoord0.y);                        \n"
    "    }                                                                               \n";


static const char* kGlfsYuv420pToRgb =
    "    // Pixel Shader                                                                 \n"
    "    precision highp float;                                                           \n"
    "    uniform lowp sampler2D  ImageInput0    ;                                             \n"
    "    uniform lowp sampler2D  ImageInput1    ;                                             \n"
    "    uniform lowp sampler2D  ImageInput2    ;                                             \n"
    "    varying highp vec2 v_texCoord0;                                                       \n"
    "    uniform float y_offset=16（limited range）/0（full range）;                                                         \n"
    "    uniform mat3 um3_ColorConversion;                            \n"
    "                                                                                    \n"
    "    void main(void)                                                                 \n"
    "    {                                                                               \n"
    "        mediump vec3 yuv;                                                           \n"
    "        lowp vec3 rgb;                                                              \n"
    "        yuv.x = texture2D(ImageInput0, v_texCoord0.xy).r - (y_offset / 255.0);      \n"
    "        yuv.y = texture2D(ImageInput1, v_texCoord0.xy).r - 0.5;                     \n"
    "        yuv.z = texture2D(ImageInput2, v_texCoord0.xy).r - 0.5;                     \n"
    "        rgb = um3_ColorConversion * yuv;                      \n"
    "                                                          \n"
    "        gl_FragColor = vec4(rgb, 1.0);                                             \n"
    "    }                                                                               \n";
}