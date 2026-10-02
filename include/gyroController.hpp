

namespace speedometer{
// Constructor for IMU
    class GYRO{
        public:
            float getHeading();

            float getPitch();

            float getRoll();

            void initGyro();

            bool begin();

            float gyroTimer();

        private:
            float lastTime = 0;
            float radHeading;
            float radPitch;
            float radRoll;
            

    };
}