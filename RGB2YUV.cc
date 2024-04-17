static const GLfloat kBt601VideoRangeRGB2YUVMatrix[] = {
  0.256788, -0.144914, 0.429412,
  0.515639, -0.290993, -0.367788,
  0.100141, 0.439216, -0.071427,
};

static const GLfloat kBt601FullRangeRGB2YUVMatrix[] = {
  0.299, -0.168736, 0.500,
  0.587, -0.331264, -0.418688,
  0.114, 0.500, -0.081312,
};

static const GLfloat kBt709VideoRangeRGB2YUVMatrix[] = {
  0.182586,  -0.098397, 0.429412,
  0.628254, -0.338572, -0.398942,
  0.063423, 0.439216, -0.040274,
};

static const GLfloat kBt709FullRangeRGB2YUVMatrix[] = {
  0.2126,  -0.114572, 0.5000,
  0.7152, -0.385428, -0.454153,
  0.0722, 0.5000, -0.045847,
};

static const GLfloat kBt2020VideoRangeRGB2YUVMatrix[] = {
  0.225613,  -0.119918, 0.429412,
  0.595576, -0.316560, -0.403890,
  0.052091, 0.439216, -0.035325,
};

static const GLfloat kBt2020FullRangeRGB2YUVMatrix[] = {
  0.2627,  -0.139630, 0.5000,
  0.6780, -0.360370, -0.459786,
  0.059300, 0.5000, -0.040214,
};

// Reference:   http://www.equasys.de/colorconversion.html
static const char* kGlfsRgbToYuv420p =
    "    // Pixel Shader                                                                 \n"
    "    precision highp float;                                                           \n"                                               
    "    uniform sampler2D  ImageSampler;                                             \n"
    "    varying vec2 v_texCoord0;                                                       \n"
    "    uniform   mat3 um3_ColorConversion;                                             \n"
    "    uniform   float y_offset=16（limited range）/0（full range）;                                                        \n"
    "                                                                                    \n"
    "    void main(void)                                                                 \n"
    "    {                                                                               \n"
    "        lowp vec3 yuv;                                                               \n"
    "                                                                                   \n"
    "        vec4 rgba = texture2D(ImageSampler, v_texCoord0.xy);                         \n"
    "        yuv = um3_ColorConversion * rgba.rgb;                                              \n"
    "        yuv.r = yuv.r + (y_offset / 255.0);                                                  \n"
    "        yuv.g = yuv.g + 0.5;            \n"
    "        yuv.b = yuv.b + 0.5;             \n "
    "        gl_FragColor = vec4(yuv, 1.0);                                          \n"
    "    }      