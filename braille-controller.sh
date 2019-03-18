#! bin/bash

source env/bin/activate
java -jar ~/processing.py-3017-linux64/processing-py.jar Braille-Controller.py &
python serial-sender.py &