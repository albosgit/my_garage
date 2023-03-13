//一阶低通滤波 
//deltaT:采样周期；  M_PI=3.1415926;  Fcut:截止频率; olddata:上一次滤波输出；newdata:本次采样值
#define M_PI 3.1415926
float LPF_1st(float olddata, float newdata, float deltaT, float Fcut)
{
	float lpf_factor = deltaT / (deltaT + 1/(2*M_PI*Fcut));

	return olddata*(1-lpf_factor)+newdata*lpf_factor;
}




