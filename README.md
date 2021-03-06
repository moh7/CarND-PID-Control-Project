# Udacity Self-Driving Car Enginer Nanodegree - PID Control Project

## Instruction
The purpose of this project was to design and implement a PID controller for a self driving car. The simulator provides cross-track error (CTE), speed and steering angle data via local websocket. The designed controller has to respond with steering angle and throttle values to keep the car on the simulator track.

## Ruberic Discussion Points
**Describe the effect of the P, I, D component of the PID algorithm in the implementation.**

The P component shows the most significant effect on the performance of the controller. The P component produces an steering angle proportional to the distance of the car from the track centerline (CTE). If the car is far from the centerline, the P component generates a large control input to return the car back to the centerline. If the car is a slightly far from the centerline, it produces a smaller control input to return the car. Large values of the P component will lead to an undesired control performance, destabilizing the car and making it oscillate harder to left and right. I started testing the controller with Kp = 2 and decreased it to 0.12 until I got an acceptable performance.

The D component adds damping to the controller performance and counteracts the effect of the P component to overshoot and helps the car to make smoother turns. I initially set Kd = 0 and gradually increased its value until I obtained an acceptable performance. Increasing Kd more than 5 did not show a significant improvement in the performance of the controller.

The I component compensates for the bias in the CTE which keeps the car from reaching the center line. It can be effective if there is a bias in the system such as a steering drift. However, in this particular scenario, I did not notice any improvement in the performance by adding an integrator and therefore set this parameter to zero.

The final parameters that I used for the PID controller are: Kp = 0.12, Kd = 5.0 and Ki = 0.0.

The performance the PID controller with these parameters can be seen in this [video](https://github.com/moh7/CarND-PID-Control-Project/blob/master/simulation.mov).

---
## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

In order to run this program:

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.
5. Open the simulator and run PID controller project. (download the simulator term 2 from [here](https://github.com/udacity/self-driving-car-sim/releases).

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)


## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.
