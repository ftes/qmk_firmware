# How to use
1. `sudo apt install gcc-avr avr-libc avrdude`
2. `sudo pip3 install -r requirements.txt`
3. `sudo systemctl disable ModemManager.service` (on ubuntu)
4. `sudo usermod -a -G dialout $USER`
5. `make redox_w:ftes:avrdude`
6. when prompted to reset press the reset soft key (of configured in keymap) or the round hardware reset button on the arduino shield
