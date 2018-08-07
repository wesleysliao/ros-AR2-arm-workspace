#include <controller_manager/controller_manager.h>

void main()
{
  AR2Robot ar2;
  controller_manager::ControllerManager cm(&robot);

  while (true)
  {
     ar2.read();
     cm.update(ar2.get_time(), ar2.get_period());
     ar2.write();
     sleep();
  }
}