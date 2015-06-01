#!/usr/bin/python


# to use C fcns calls
from ctypes import cdll, c_int, c_ulong
import ctypes
# to execute shell commands
import subprocess


# to have a GUI interface ( could be replaced by PyGame I think ;p )
from Tkinter import *


# C lib init
#lib = "/usr/lib/libdesktopwindow.so"
#dll = cdll.LoadLibrary(lib)


# C lib fcns call tests

# setup and  execute C fcns calls
#foo = ( dll.foo() )

#reparentWindowTo = ( lambda pyWinId,deskWinId,x,y: dll.reparentWindowTo(c_int(pyWinId), c_int(deskWinId), c_int(x), c_int(y) ))

#reparentWindowTo(pyWinId, deskWinId, 0, 0)

# mouseMove = (lambda x,y: dll.mouseMove(c_int(x), c_int(y)))
# mouseMove(xshift, yshift)


## shell commands execution tests

# execute a shell command
cmdoutput = subprocess.check_output("echo Hello World !", shell=True)
print cmdoutput

# execute a shell command with a parameter
deskWinName = "Desktop"
deskWinId = subprocess.Popen(['./WinIdGetter.sh', '-name', deskWinName], stdout = subprocess.PIPE).communicate()[0]
print deskWinId




# GUI init stuff ( TKinter )
root = Tk()
# var that holds the name of the window
pyWinName = "DesktopWindowPython"
root.wm_title(pyWinName)


def task():
    print "scheduled task: getting the TKinter WinId"
    # by now, as our WTKinter window has a name, we can retrieve its WinId easily using a shell command a a bash script
    pyWinId = subprocess.Popen(['./WinIdGetter.sh', '-name', pyWinName], stdout = subprocess.PIPE).communicate()[0]
    print pyWinId
    
    # TODO: call a C fcn from the Lib that reparent the python TKinter Window to the root window ( using 'deskWinId' and 'pyWinId' vars  )
    #foo = ( dll.foo() )

    # wip implm - dirty hack
    #reparentWindowTo(pyWinId, deskWinId, 0, 0)
    #print "The window should now have been reparented succefully ..."

    #root.after(2000,task)  # reschedule event in 2 seconds

# schedule the task of getting the WinId after 2 seconds ( the window shold be visible at that point )
root.after(2000,task)

# TKinter loop  

root.mainloop()
