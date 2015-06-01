#!/usr/bin/python

# to use C fcns calls
from ctypes import cdll, c_int
# to execute shell commands
import subprocess

lib = "/usr/lib/libdesktopwindow.so"
dll = cdll.LoadLibrary(lib)

# execute a C fcn call
foo = ( dll.foo() )

# execute a shell command
cmdoutput = subprocess.check_output("echo Hello World !", shell=True)
print cmdoutput

# execute a shell command with a parameter
deskWinName = "Desktop"
deskWinId = subprocess.Popen(['./WinIdGetter.sh', '-name', deskWinName], stdout = subprocess.PIPE).communicate()[0]
print deskWinId
