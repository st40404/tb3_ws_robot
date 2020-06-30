# Tb3_ws_robot

Play tb3 with two UTM-30LX lidar

<!-- TOC -->
- [Tb3_ws_robot](#Tb3_ws_robot)
- [Platform](#Platform)
- [Permission](#Permission)
- [Tb3_driver](#Tb3_driver)
- [UTM-30LX_driver](#UTM-30LX_driver)
- [Permission](#Permission)
- [Permission](#Permission)
- [Permission](#Permission)
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
## Tb3_driver
```bash
$ roslaunch turtlebot3_bringup turtlebot3_core.launch
```
## UTM-30LX_driver
 * This launch include 
    - UTM-30LX front and back driver (lidar_front/urg_node, lidar_back/urg_node)
    - Two translate TF for two Lidar (new_tf)
    - merge two scan data to one (laserscan_multi_merger)
   ```bash
   $ roslaunch urg_node urg_lidar.launch
   ```


































