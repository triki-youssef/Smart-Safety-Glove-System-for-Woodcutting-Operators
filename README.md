<h1>🧤 Smart Safety Gloves for Woodcutting Machine Activation</h1>

<h2>📘 Project Description:</h2>

This project introduces a smart safety glove system designed to control the operation of a woodcutting machine using direct skin contact detection. The system ensures that the machine can only be activated when the glove is being worn properly and securely by the operator, adding a vital safety layer to industrial woodcutting environments.

Inside the glove is 2 conductive plates , where two soldered lines are connected to wires leading to a Wemos D1 Mini microcontroller. When the glove is worn and skin touches both solder lines, a signal is sent to another D1 Mini that controls the woodcutting machine.

🟢 If the glove is being worn: the system detects skin contact → machine starts

🔴 If skin contact is lost for more than 5 seconds: system stops the machine automatically

This ensures the machine runs only under safe, supervised, and proper handling conditions.
<br />


<h2>📶 Architecture Overview:</h2>

🔌 D1 Mini (Machine-Side):

Acts as a Wi-Fi Access Point (Hotspot)

Controls the relay (L298N Motor-Driver) connected to the cutting machine (Table + Motor)

Receives a signal from the glove-side board to start or stop the machine

🧤 D1 Mini (Glove-Side):

Connects as a Wi-Fi client to the machine-side access point

Continuously checks for skin contact with two soldered lines

Sends a message to the machine-side 

<h2> Components and Tools Used </h2>

 <h3> - 🤖 MicroControllers : </h3>

 <h4> Wemos D1 Mini : </h4>
<h5> 	ESP8266-based Wi-Fi board (1 as Sender in glove, 1 as Receiver on machine) </h5> 
 <h3> - 👁️‍🗨️ Sensors :  </h3>
 <h4> Copper Plates : </h4>
<h5> Used as touch/contact pads (conductive surface) </h5>
 <h3> - 🚗 Actuators & Drivers : </h3>
 <h4> 3-6V Motor </h4>
 <h4> L298N Motor Driver </h4>
 <h3> - 🔋 Power Supply : </h3>
 <h4> 9V,2A : For The Machine Side </h4>
<h4> 3.7V,500mAh : For The Glove Side </h4>
 <h4> TP4056 Charge Module : For The Glove Side </h4>
 <h3> -  🧤 Special Gloves : For the Operator </h3>
 <h3> - 🧑‍💻 SoftWare Used : </h3>
 <h4> Arduino IDE : For programming the microcontroller firmware </h4>
  <h4>TinkerCad  : For Designing The Table </h4>
  <h4>Cura  : Slicer </h4>
  <h3>  - 🌐 Communication Protocols : </h3>
  <h4>Wireless communication is done via ESP-AP WiFi using HTTP POST.</h4>
   <h3> - 🖨️ 3D Printer : </h3>
   <h4>Creality Ender-3v2 </h4>
  







<h2> 📁You will find the following resources in the project files:</h4>

<h3>💻 Source Codes </h3>

<h3>🔌 Wiring Diagrams </h3>

<h3>🧩 3D Designs </h3>

<h3>🎥 Prototype Media (images & videos) </h3>



<!--
 ```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ text in purple (and bold)@@
```
--!>
