/* programwin.h - simple program window using a class - by StephaneAG - 2013  */
#include <QtGui>
#include <QWidget>

//#include "dialogwindow.h" // include the local Kupa Node settings editing dialog ( used to change the parameters of the local Kupa Node )

/*class Programwin : public QWidget*/
class Programwin : public QMainWindow
{
	Q_OBJECT

	public:
		Programwin();
		void centerOnScreen(); // to be called from 'main.cpp' after calling 'show()' on the QMainWindow ( could maybe be moved to an overloaded show() fcn ? ( ... ) )

	private slots:
		void openSlot(); // corresponds to the 'QAction openAction'
		void saveSlot(); // corresponds to the 'QAction saveAction'
		void quitSlot(); // corresponds to the 'QAction exitAction'
		void savekclSlot(); // corresponds to the 'QAction savekclAction'
		void resetkclSlot(); // corresponds to the 'QAction resetkclAction'
		void backupkclSlot(); // corresponds to the 'QAction backupkclAction'
		void newclientkclSlot(); // corresponds to the 'QAction newclientkclAction'
		void sshpairingkclSlot(); // corresponds to the 'QAction sshpairingkclAction'
		void kupanodesettingsSlot(); // corresponds to the 'QAction editkupanodesettings'
		void aboutSlot(); // corresponds to the 'QAction about'

		void dummySlot(); // test-implm of a button in the table view
		//void dummySlot2(const QModelIndex & index); // same as above

		void cellClickedSlot(const QModelIndex & index); // triggered when a cell click occurs
		void cellActivatedSlot(const QModelIndex & index); // triggered when a cell is activated ( & thus, 'highlighted' )
	private:
		QTextEdit *textEdit; // from the 'Notepad' Qt example
		QPushButton *quitButton; // same as above
		
		
		// ------ App stuff ------ //
		
		//the window's top bar menu's actions
		QAction *openAction;
		QAction *saveAction;
		QAction *exitAction;
		QAction *savekclAction;
		QAction *resetkclAction;
		QAction *backupkclAction;
		QAction *newclientkclAction;
		QAction *sshpairingkclAction;
		QAction *kupanodesettingsAction;
		QAction *aboutAction;

                // the window's top bar menu
		QMenu *fileMenu; // the OS's topbar menu
                
		// Kupa clients list editor specific elements below
		// the labels
		QLabel *appnameLabel; // the application name label
		QLabel *subtitleLabel; // the application subtitle label
		// the buttons
		QPushButton *savekclButton; // the save button
		QPushButton *resetkclButton; // the reset button
		QPushButton *backupkclButton; // the backup button
		QPushButton *newclientkclButton; // the new client button
		QPushButton *sshpairingkclButton; // the SSH pairing button
		// the model consumed by the table view
		QStandardItemModel model; // a model we will customize to our needs
		// the string list used as the table view rows data
		QList<QStringList> rows;
		// the table view
		QTableView *kclistView; // the unique table view
		// the layouts
		QVBoxLayout *mainLayout; // the main layout of the program window
		QHBoxLayout *appheaderLayout; // the layout of the app header
		QVBoxLayout *appinfosLayout; // the layout holding the App name & the subtitle
		QVBoxLayout *appbuttonsLayout; // the layout holding the app header buttons layouts
		QHBoxLayout *appsrbbuttonsLayout; // the layout holding the save, reset & backup buttons
		QHBoxLayout *appcsbuttonsLayout; // the layout holding the new client & the ssh pairing buttons

		// the central widget
		QWidget *centralWidget;

		void handleKupaSettingsExistenceAtStartup(); // check the existence of a settings.kupa file & act accordingly
		void fillTableModelWithRows(QList<QStringList>); // fill the table view model with rows ( QList<QStringList> )
		void fillFileWithTableData(); // fill a file with the data currently present in the table view model
		void resetTableData(); // remove all the rows present in the table model & append an empty line in it
		void backupkSettingsFile(); // do a backup of the settings.kupa file

		// re-implms
		void resizeEvent(QResizeEvent *event); // we re-implm the QMainWindow::resizeEvent to handle it
		void closeEvent(QCloseEvent *event); // we re-implm the QMainWindow::closeEvent to handle it

		// getting an error when isntanciating a QDIalog, let's see if it works declaring it from here ( ... )
		//DialogWindow * dialwin; // same error ( -> trying other way ( ... ) )

};
