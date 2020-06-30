# Tb3_ws_robot

Play tb3 with two UTM-30LX lidar

<!-- TOC -->
- [Tb3_ws_robot](#Tb3_ws_robot)
- [Platform](#Platform)
- [Download_pkg](#Download_pkg)
- [Permission](#Permission)
- [Tb3_driver](#Tb3_driver)
- [UTM-30LX_driver](#UTM-30LX_driver)
- [Slam](#Slam)
- [Navigation](#Navigation)
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
## Download_pkg
 * Install pkg as follow
   ```bash
   $ sudo apt-get install ros-melodic-mapserver
   $ sudo apt-get install ros-melodic-move-base
   $ sudo apt-get install ros-melodic-dwa-local-planner
   ```
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
    - Merge two scan data to one (laserscan_multi_merger)
   ```bash
   $ roslaunch urg_node urg_lidar.launch
   ```
## Slam
 * This launch can choose your slam method
    - Change the default and doc of arg( slam_methods )
    - Need to publish /scan topic from lidar 
   ```bash
   $ roslaunch turtlebot3_slam turtlebot3_slam.launch
   ```
 * Can use this launch to open launch of TB3/Lidar driver and slam
   ```bash
   $ roslaunch turtlebot3_integration tb3_integration.launch
   ```
 * Control the motion of TB3
   ```bash
   $ roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
   ```
 * Save the map what you make
   ```bash
   $ rosrun map_server map_saver -f test_map
   ```
## Navigation
 * This launch include ACML and move_base, you also can set the detail of obstacle and particle in AMCL 
 * Need to give the path of ori map
   ```bash
   $ roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/tb3_ws/tb3_hse.yaml
   ```




























