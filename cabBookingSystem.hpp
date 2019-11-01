class coordinates{
    double latitude;
    double longitude;
    public:
        coordinates(double lat = 0, double lon = 0){
            latitude = lat;
            longitude = lon;
        }
        double distance(coordinates other);
};