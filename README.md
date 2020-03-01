# ControlFANs
Simple GUI written in QT to configure FAN PWM via HWMON interface.
You could use it to setup the kernel auto point for every FAN who support it.

# Build
```bash
$ git clone https://github.com/amedeos/ControlFANs
$ cd ControlFANs
$ qmake
$ make
```

# Usage
You can start ControFANs with sudo in order to edit hwmon files, otherwise, if you start it as normal user you could only see the fan configuration.

![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-01.png)
![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-02.png)
![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-03.png)
![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-04.png)
![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-05.png)
![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-06.png)
![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-07.png)

```bash
$ cat /etc/systemd/system/controlfan-hwmon0-fan2.service
[Unit]
Description=controlfan hwmon0 fan2
DefaultDependencies=no
After=sysinit.target local-fs.target suspend.target hibernate.target
Before=basic.target

[Service]
Type=oneshot
ExecStart=/bin/sh -c 'echo 104 > /sys/class/hwmon/hwmon0/pwm2'
ExecStart=/bin/sh -c 'echo 51 > /sys/class/hwmon/hwmon0/pwm2_auto_point1_pwm'
ExecStart=/bin/sh -c 'echo 20000 > /sys/class/hwmon/hwmon0/pwm2_auto_point1_temp'
ExecStart=/bin/sh -c 'echo 80 > /sys/class/hwmon/hwmon0/pwm2_auto_point2_pwm'
ExecStart=/bin/sh -c 'echo 30000 > /sys/class/hwmon/hwmon0/pwm2_auto_point2_temp'
ExecStart=/bin/sh -c 'echo 140 > /sys/class/hwmon/hwmon0/pwm2_auto_point3_pwm'
ExecStart=/bin/sh -c 'echo 40000 > /sys/class/hwmon/hwmon0/pwm2_auto_point3_temp'
ExecStart=/bin/sh -c 'echo 200 > /sys/class/hwmon/hwmon0/pwm2_auto_point4_pwm'
ExecStart=/bin/sh -c 'echo 50000 > /sys/class/hwmon/hwmon0/pwm2_auto_point4_temp'
ExecStart=/bin/sh -c 'echo 255 > /sys/class/hwmon/hwmon0/pwm2_auto_point5_pwm'
ExecStart=/bin/sh -c 'echo 65000 > /sys/class/hwmon/hwmon0/pwm2_auto_point5_temp'

[Install]
WantedBy=basic.target suspend.target hibernate.target
```

![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-08.png)
![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-09.png)
![Picture](https://github.com/amedeos/ControlFANs/blob/master/images/ControlFANs-howto-10.png)

