# Robocar
A simple 3D-printed cylindrical robocar, that can follow a fixed path or can be remote controlled. It is controlled by an Arduino Uno and uses batteries or a powerbank. 

## What does it do?
The robot can follow either follow a fixed path or be remote controlled. Example code including functions for a fixed path are given. There is also a code with which you can manually control the robot with the remote. It only moves if you press the arrow keys, but you can also press some buttons to make it follow a fixed path. The robot can be coded as wanted. 
</br></br>
Demo 1 (Fixed path): https://youtu.be/czfSZnnJx2o </br>
Demo 2 (Remote-controlled): https://www.youtube.com/shorts/nxYcud6KOsA

## Parts required
- 3D-printed parts
- Arduino (Uno)
- Breadboard if wanted
- rubber or similar if wanted (to increase friction of wheels)
- 2 TT gear motors
- 1 Metal Ball Caster
- 2 screws
- TB6612FNG Dual Driver
- Infrared Remote and Sensor
- Batteries (~6V and enough current supply) or Powerbank
- Cylindrical Magnets (6x2mm)

## How to build it yourself
### Print parts
If you want my default settings (dimensions set such that Creality CR-10 SE can print it), just download all 4 .3mf-files, slice it and print. Dimensions are 200x200x60mm. </br>
If you want to make some adjustments, first download Robocar 1.FCStd (FreeCAD). You can adjust many things through the variables in VarSet. The wheels and wheel axis need to be edited manually as they do not use the variables. Just make sure there is enough gap to enter the wheel from the top. Then export the files, slice and print. </br>
You need to print 2 wheels and 2 wheel axes. You need only one each of the main body and lid. 

### Assembly
If wanted, add rubber (or anything that increases friction) around the wheels. Insert the wheels from the top and fix them with the axis. Stick it with glue if everything else works. Attach the motors from the inside, making them face outwards, so there's place in the center to place a breadboard/powerbank/batteries/etc. </br>
In the back insert the ball caster and fasten it with screws. </br>
Place the Arduino between the motors such that the cable can be inserted from the center. </br> 
Put 2 magnets in each slot on the main body and 1 magnet per slot in the lid. </br>
If everything seems fine, then fix the wheel axis to the wheel with glue. Fix the motors in place, for example with double-sided tape. It's also a good idea to fix other things like Arduino and breadboard, but it isn't required. Then solder all the parts according to the schematics. Make sure the lid fits on top and has enough force. 
