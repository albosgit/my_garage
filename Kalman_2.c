//卡尔曼滤波
//ResrcData  修复的值(输入的数据) x_last  上一次值 p_last 先验估计协方差
//ProcessNoise_Q  过程噪声协方差  MeasureNoise_R 测量噪声协方差
//q增大，动态响应变快，收敛稳定性变差
//r增大，动态响应变慢，收敛稳定性变好
//q=0.02,p=0.9,r=8
float KalmanFilter(float ProcessNoise_Q,float p_last,float MeasureNoise_R,const float ResrcData,float x_last)
{
	float R = MeasureNoise_R;
	float Q = ProcessNoise_Q;
	float x_mid = x_last;
	float x_now;
	float p_mid;
	float p_now;
	float kg;
	
	x_mid=x_last;
	p_mid=p_last+Q;
	kg=p_mid/(p_mid+R);
	x_now=x_mid+kg*(ResrcData-x_mid); //最优值估计
	
	p_now=(1-kg)*p_mid;//最优值对应的协方差
	p_last=p_now;
	x_last=x_now;
	
	return x_now;
}


