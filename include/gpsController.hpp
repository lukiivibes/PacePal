namespace speedometer{
// THE constructor for GPS
    class GPS{
        public:
            float getLong();

            float getLat();

            void begin();

            float getSpeed(); // current Hz = 3
        
            private:
            int deltaTime = 0; //time in seconds
            //current/final
            float FLong = 0;
            float FLat = 0;
            //change
            float ChangeLong = 0;
            float ChangeLat = 0;
            //initial
            float ILong = 0;
            float ILat = 0;

            int R = 6378137;  //radius of earth/equator
            

    };
}

12.00
14.00
15.00
15.0
