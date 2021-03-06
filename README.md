# Pulse-oximeter-mobile-app
Mobile application with usage of Arduino Uno and pulse oximeter sensor.

## Project structure 


Pulse oximeter and bluetooth module is connected to Arduino uno. Script prepared for uno board allows to measure pulse and send data through bluetooth to mobile app. 
Photo below shows physical connection of Arduino board and modules (bluetooth and pulse oximeter). 
 - 1 Arduino board
 - 2 Bluetooth module that allows connection with mobile phone
 - 3 Pulse oximeter, user must keep the finger where the red led lamp lights up

![image](https://user-images.githubusercontent.com/44081987/153500020-2137b582-c5b0-463d-a5a1-bcd0af34c927.png)


## Mobile application

Mobile app code implements user interface. In the center of the screen there is an animation of heartbeat with value of BPM (heart beats per minute). At the bottom, there is a connection status bar, proper information is displayed depending on connection status. Photo below shows first stage, when arduino board is not connected and there is no received data: 

![image](https://user-images.githubusercontent.com/44081987/153317212-5971da11-975b-426c-ad2f-5ce9640b47ac.png)


### User option buttons

There are two buttons, at top right corner there is a button that allows to disconnect bluetooth connection between arduino and mobile phone. At left corner there is a button that allows user to choose device form list of saved bluetooth devices, this is shown on photo below: 

![image](https://user-images.githubusercontent.com/44081987/153317092-59f2fe82-5878-4556-a40c-ec95dc20d860.png)

## Presenting received data from oximeter:

When Arduino board is sending measured data to app, this data is displayed next to BPM label, informing user about his pulse. In addition, status bar is showing that 
device is connected with green label.
 
![image](https://user-images.githubusercontent.com/44081987/153316185-ccfca566-b067-41b3-a511-692a8a9fd4b2.png)


