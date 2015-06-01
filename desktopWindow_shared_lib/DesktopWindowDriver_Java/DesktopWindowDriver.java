/* desktopwindow Java driver example program - by StephaneAG - 2013 */

// imports
import com.sun.jna.Library;
import com.sun.jna.Native;


public class DesktopWindowDriver {
		

	/* java interface wich 'bridges' with the C shared library */
	public interface DesktopWindow extends Library {
		public void foo(); // name of the C fcn defined in the 'desktopwindow.h' & implemented in 'desktopwindow.c'
	}

	/* java program 'main' */
	static public void main(String argv[]){
		DesktopWindow desktopwindow = (DesktopWindow) Native.loadLibrary("desktopwindow", DesktopWindow.class);
		desktopwindow.foo(); // run the C fcn 'foo()' ( wich should print "Hello World ! " to stdout)
	}
}


//public interface libdesktopwindow extends Library {
//	desktopwindow INSTANCE = (libdesktopwindow) Native.loadLibrary("desktopwindow", desktopwindow.class);
//void foo();
//}

///* not sure the following goes in that file (...) */
//static {
//	System.setProperty("jna.library.path", "/usr/lib/libdesktopwindow.so");
//}

/* if tha tdirty little test works from here, I must admit I'd be happily surprised ;) */
//libdesktopwindow.INSTANCE.foo();
