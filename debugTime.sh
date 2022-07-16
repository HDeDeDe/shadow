#! /bin/bash
export PATH=$PATH:/usr/bin
/usr/bin/konsole -e "gdbserver :4444 ./ShadowDebug"
