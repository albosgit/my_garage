
//二阶低通滤波
#define M_PI 3.1415926
typedef struct
{
	float b0;
	float a1;
	float a2;
	float preout;
	float lastout;
}LPF2ndData_t;

//LPF2ndData_t:滤波器系数结构体；newdata:本次采样值；deltaT:采样周期； Fcut:截止频率;
float LPF_2nd(LPF2ndData_t* lpf_2nd,float newdata,float deltaT,float Fcut)
{
	float a = 1/(2*M_PI*Fcut*deltaT);
	lpf_2nd->b0 = 1/(a*a+2*a+1);
	lpf_2nd->a1 = (2*a*a+2*a)/(a*a+2*a+1);
	lpf_2nd->a2 = (a*a)/(a*a+2*a+1);
	
	float lpf_2nd_data;
	lpf_2nd_data = newdata*lpf_2nd->b0+lpf_2nd->lastout*lpf_2nd->a1-lpf_2nd->preout*lpf_2nd->a2;
	lpf_2nd->preout = lpf_2nd->lastout;
	lpf_2nd->lastout = lpf_2nd_data;
	
	return lpf_2nd_data;
}