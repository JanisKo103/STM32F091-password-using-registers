# STM32F091 password using registers
<b>This is an STM32CubeIDE project in low level C language for STM32F091RC MCU that turns on a red or green LED depending on the passcode entered.</b>

This is a low level C program for STM32F091RC microcontroller. There are ten buttons connected from PA4 to PA13. One LED is connected to PA4 and one LED to PA5 to display the result depending if the password entered is correct or incorrect. Green LED turns ON if the password is entered correctly, red is turned ON if password is enetered incorrectly. The corresponding LED stays ON for few seconds and than turns OFF. After that the next attemt can be made to enter the password.

<img src="https://user-images.githubusercontent.com/122583353/213829383-2f394c4f-ac73-46e7-b7cb-2174147690e3.jpg" alt="Runing LEDs" width="605" height="454">

To create this program STM32CubeIDE was used. Here are the download links to download the necessary software:

<ul>
<li>STM32CubeMX download link: https://www.st.com/en/development-tools/stm32cubemx.html</li>
<li>STM32CubeIDE download link: https://www.st.com/en/development-tools/stm32cubeide.html</li>
<ul>
  
  
