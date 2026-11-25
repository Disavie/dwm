#!/bin/sh
#xrandr --output HDMI1 --mode 1920x1080 --rate 120
#xrandr --output eDP1 --off

feh --bg-fill ~/wallpapers/HVzzirDXoAAMeOC.jpg
picom &
slstatus &
exec dwm
