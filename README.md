# Tb3_ws_robot

Play tb3 with two UTM-30LX lidar

<!-- TOC -->
- [Tb3_ws_robot](#Tb3_ws_robot)
- [Platform](#Platform)
- [Permission](#Permission)
- [Tb3 driver](#Tb3 driver)
- [UTM-30LX deiver](#UTM-30LX deiver)
- [Permission](#Permission)
- [Permission](#Permission)
- [Permission](#Permission)
<!-- /TOC -->

## Platform
 * Lidar
   - Hokuyo UTM-30LX *2
 * Controller
   - NUC-i7-5557u
 * System
   - ROS melodic
 * Robot
   - TURTLEBOT3(waffle)

## Permission
 * Give the driver permission of TB3 and Lidar
 * Sequence of open port: Tb3(ttyACM0)-> front_lidar(ttyACM1)-> back_lidar(ttyACM2) 
   ```bash
   $ sudo chmod 777 /dev/ttyAcm0
   $ sudo chmod 777 /dev/ttyAcm1
   $ sudo chmod 777 /dev/ttyAcm2
   ```
## Tb3 driver
```bash
$ roslaunch turtlebot3_bringup turtlebot3_core.launch
```
## UTM-30LX deiver
 * This launch include 
    - Two translate TF for two Lidar
    - TURTLEBOT3(waffle)

   ```bash
   $ roslaunch urg_node urg_lidar.launch
   ```


































