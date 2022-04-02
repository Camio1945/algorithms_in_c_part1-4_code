/** program_04_14 */

/** 复数结构体 */
typedef struct {
  float Re; // 实部
  float Im; // 虚部
} Complex;

Complex COMPLEXinit(float, float);

float Re(Complex);

float Im(Complex);

Complex COMPLEXmult(Complex, Complex);
