cmd_/home/david/Desktop/repos/proyecto-ode/src/ODEcam/driver/Module.symvers := sed 's/\.ko$$/\.o/' /home/david/Desktop/repos/proyecto-ode/src/ODEcam/driver/modules.order | scripts/mod/modpost -m -a  -o /home/david/Desktop/repos/proyecto-ode/src/ODEcam/driver/Module.symvers -e -i Module.symvers   -T -