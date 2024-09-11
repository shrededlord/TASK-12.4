
class PIDController {
  private:
    float Kp, Ki, Kd;    // PID coefficients
    float setPoint;      // Desired speed
    float integral;
    float previousError;
    unsigned long lastTime;

  public:
    PIDController(float p, float i, float d) {
      Kp = p;
      Ki = i;
      Kd = d;
      setPoint = 0;
      integral = 0;
      previousError = 0;
      lastTime = millis();
    }

    void setTarget(float target) {
      setPoint = target;
    }

    float compute(float currentSpeed) {
      unsigned long now = millis();
      float timeChange = (now - lastTime) / 1000.0;  // in seconds
      lastTime = now;

      float error = setPoint - currentSpeed;
      integral += error * timeChange;
      float derivative = (error - previousError) / timeChange;

      float output = (Kp * error) + (Ki * integral) + (Kd * derivative);
      previousError = error;

      return output;
    }
};