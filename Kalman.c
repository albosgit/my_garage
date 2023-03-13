//卡尔曼滤波结构体
typedef struct KalmanFilter 
{
	float x_mea;	 // 测量值
	float x_est;	 // 估计值
	float e_mea;	 // 测量偏差
	float e_est;	 // 估计偏差
	float Kk; 		 // Karlman 增益
}type_KalmanFilter;

//Kalman初始化
void Kalman_Init(type_KalmanFilter* kalmanFilter, float FirstMeaValue, float E_mea, float FirstEstValue, float E_est) 
{
	kalmanFilter->x_est = FirstEstValue;
	kalmanFilter->x_mea = FirstMeaValue;
	kalmanFilter->e_est = E_est;
	kalmanFilter->e_mea = E_mea;
	kalmanFilter->Kk = Kk_calc(kalmanFilter->e_est, kalmanFilter->e_mea);
}

//Kalman更新
void Kalman_Update(type_KalmanFilter* kalmanFilter, float newMeaValue) 
{
	float temp = kalmanFilter->e_est;
	kalmanFilter->x_est = kalmanFilter->x_est + kalmanFilter->Kk * (newMeaValue - kalmanFilter->x_est);
	kalmanFilter->x_mea = newMeaValue;
	kalmanFilter->Kk = Kk_calc(kalmanFilter->e_est, kalmanFilter->e_mea);
	kalmanFilter->e_est = (1 - kalmanFilter->Kk) * temp;
}
