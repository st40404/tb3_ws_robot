# Tb3_ws_robot

Play tb3 with two UTM-30LX lidar

<!-- TOC -->
- [Tb3_ws_robot](#Tb3_ws_robot)
- [Platform](#Platform)
- [Permission](#Permission)
<!-- /TOC -->

## Platform
 * Lidar
   - Hokuyo UTM-30LX *2
 * NUC-i7-5557u
 * ROS melodic
 * Robot
   - TURTLEBOT3(waffle)

## Permission
 * give the driver permission of TB3 and Lidar
 * sequence of open port: Tb3(ttyACM0)-> front_lidar(ttyACM1)-> back_lidar(ttyACM2) 
   ```bash
   $ sudo chmod 777 /dev/ttyAcm0
   $ sudo chmod 777 /dev/ttyAcm1
   $ sudo chmod 777 /dev/ttyAcm2
   ```



































