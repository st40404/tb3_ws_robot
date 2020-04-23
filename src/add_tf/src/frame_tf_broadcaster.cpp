#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcaster");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(10.0);

  double new_x, new_y, new_z;
  double new_rx, new_ry, new_rz, new_rw;
  std::string tf_name;


  node.getParam("new_x",  new_x);
  node.getParam("new_y",  new_y);
  node.getParam("new_z",  new_z);
  node.getParam("new_rx", new_rx);
  node.getParam("new_ry", new_ry);
  node.getParam("new_rz", new_rz);
  node.getParam("new_rw", new_rw);
  node.getParam("tf_name", tf_name);

  while (node.ok()){
    transform.setOrigin( tf::Vector3(new_x, new_y, new_z) );
    transform.setRotation( tf::Quaternion(new_rx, new_ry, new_rz, new_rw) );
    // transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
    // transform.setRotation( tf::Quaternion(0.0, 0.0, 0.0, 1) );
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link", tf_name));
    rate.sleep();
  }
  return 0;
};
