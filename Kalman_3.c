
float P=1;
float P_;  //对应公式中的p'
float X=0;
float X_;  //X'
float K=0;
float Q=0.01;
float R=0.2;
//H 就视为1了，不需要变换

float KLM(float Z)
{
  X_=X+0;
  P_=P+Q;
  K=P_/(P_+R);
  X=X_+K*(Z-X_);
  P=P_-K*P_;
  return X;
}