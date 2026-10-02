

namespace speedometer{
// Constructor for IMU
    class IMU{
        public:
            float getX();

            float getY();

            float getZ();

            float getgX();

            float getgY();

            float getgZ();

            void getSensorDetails(void);

            void initAccel();

            bool begin();
        private:
            float GX;
            float GY;
            float GZ;
            float g = 9.80665;
    };
}