# Setup

## 1. Clone the repository
```
git clone https://github.com/RoterPanda96/mini_proj_dyn.git
```

## 2. Setup dependencies
In the cloned folder, run
```
cd catkin_ws/
rosdep install --from-paths src --ignore-src -r -y
```

## 3. Build the code
In the catkin_ws/ directory, run 
```
catkin_make
```

## 4. Usage

1-   Start the simulation environment in gazebo: open a new terminal `#1` in the catkin_ws directory and run
```
source devel/setup.bash
roslaunch jackal_gazebo jackal_world.launch 
```
2-   Start the command publisher node: open a new terminal `#2` in the catkin_ws directory and run
```
source devel/setup.bash
roslaunch command_publisher command_publisher.launch 
```
3-   Start Rviz for visulization: open a new terminal `#3` in the catkin_ws directory and run
```
source devel/setup.bash
roslaunch jackal_viz view_robot.launch
```
