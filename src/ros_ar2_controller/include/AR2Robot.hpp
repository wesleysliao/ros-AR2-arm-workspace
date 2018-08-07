#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>

class AR2Robot : public hardware_interface::RobotHW
{
public:
  AR2Robot() 
 { 
   // connect and register the joint state interface
   hardware_interface::JointStateHandle state_handle_j1("J1", &pos[0], &vel[0], &eff[0]);
   jnt_state_interface.registerHandle(state_handle_j1);

   hardware_interface::JointStateHandle state_handle_j2("J2", &pos[1], &vel[1], &eff[1]);
   jnt_state_interface.registerHandle(state_handle_j2);

   hardware_interface::JointStateHandle state_handle_j3("J3", &pos[2], &vel[2], &eff[2]);
   jnt_state_interface.registerHandle(state_handle_j3);

   hardware_interface::JointStateHandle state_handle_j4("J4", &pos[3], &vel[3], &eff[3]);
   jnt_state_interface.registerHandle(state_handle_j4);

   hardware_interface::JointStateHandle state_handle_j5("J5", &pos[4], &vel[4], &eff[4]);
   jnt_state_interface.registerHandle(state_handle_j5);

   hardware_interface::JointStateHandle state_handle_j6("6", &pos[5], &vel[5], &eff[5]);
   jnt_state_interface.registerHandle(state_handle_j6);

   registerInterface(&jnt_state_interface);

   // connect and register the joint position interface
   hardware_interface::JointHandle pos_handle_j1(jnt_state_interface.getHandle("J1"), &cmd[0]);
   jnt_pos_interface.registerHandle(pos_handle_j1);

   hardware_interface::JointHandle pos_handle_j2(jnt_state_interface.getHandle("J2"), &cmd[1]);
   jnt_pos_interface.registerHandle(pos_handle_j2);

   hardware_interface::JointHandle pos_handle_j3(jnt_state_interface.getHandle("J3"), &cmd[2]);
   jnt_pos_interface.registerHandle(pos_handle_j3);

   hardware_interface::JointHandle pos_handle_j4(jnt_state_interface.getHandle("J4"), &cmd[3]);
   jnt_pos_interface.registerHandle(pos_handle_j4);

   hardware_interface::JointHandle pos_handle_j5(jnt_state_interface.getHandle("J5"), &cmd[4]);
   jnt_pos_interface.registerHandle(pos_handle_j5);

   hardware_interface::JointHandle pos_handle_j6(jnt_state_interface.getHandle("J6"), &cmd[5]);
   jnt_pos_interface.registerHandle(pos_handle_j6);

   registerInterface(&jnt_pos_interface);
  }

private:
  hardware_interface::JointStateInterface jnt_state_interface;
  hardware_interface::PositionJointInterface jnt_pos_interface;
  double cmd[6];
  double pos[6];
  double vel[6];
  double eff[6];
};