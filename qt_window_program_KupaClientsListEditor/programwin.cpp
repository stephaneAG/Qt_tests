/* programwin.cpp - simple window using a class - by StephaneAG - 2013  */
#include "programwin.h"

#include "kupasshpairingwizard.h" // include the Kupa SSH pairing wizard class ( used to ease the process of SSH keys creation for the user )

#include "dialogwindow.h" // include the local Kupa Node settings editing dialog ( used to change the parameters of the local Kupa Node )

/* Programwin's constructor */
Programwin::Programwin()
{
	
	// initialize the different components of the window
	//textEdit = new QTextEdit(); // initiate the instance of the QTextEdit ( from 'Notepad' Qt example )
	// the central widget
	centralWidget = new QWidget();
	//the labels
	appnameLabel = new QLabel(QApplication::translate("kupaclientslisteditor", "Welcome to the Kupa clients list editor"), this);
	subtitleLabel = new QLabel(QApplication::translate("kupaclientslisteditor", "Use this app to easily specify the people you wish to add to your shared clipboard."
				                                    "\n" 
								    "Note that you still need to setup the SSH keys needed for securely pairing devices"), this);
        // the table view data model
	model.setHorizontalHeaderLabels( QStringList() 
			<< QApplication::translate("kupaclientslisteditor", "Name")
                        << QApplication::translate("kupaclientslisteditor", "Login")
                        << QApplication::translate("kupaclientslisteditor", "IP adress")
			<< QApplication::translate("kupaclientslisteditor", "Port")
			<< QApplication::translate("kupaclientslisteditor", "Kupa remote path") );
	//model.insertRow( model.rowCount() ); // add a new row at the end of the existing ones > MOVED TO THE 'newclientkclSlot()' (nb: noNE use if appended before fillinf data anyway ... )
	// the table view
	kclistView = new QTableView();
	kclistView->setModel(&model); // set the model defined above as the one for our table
	kclistView->verticalHeader()->hide(); // hide the table vetical headers ( index numbers )
	kclistView->horizontalHeader()->setStretchLastSection(true); // self-explicit
        kclistView->horizontalHeader()->setResizeMode(QHeaderView::Interactive); // allows the columns to be resized manually by the user
	kclistView->resizeColumnsToContents(); // force a resize of the columns while keeping them interactive (nb: 'd be nice to have it re-called onWIndowResize ... or not. > moved down (...)  )
	kclistView->horizontalHeader()->setClickable(false); // prevent the table headers from being clicked
	// the buttons
	savekclButton = new QPushButton(QApplication::translate("kupaclientslisteditor", "Save") , this);
	//savekclButton->show();
	resetkclButton = new QPushButton(QApplication::translate("kupaclientslisteditor", "Reset") , this);
	//resetkclButton->show();
	backupkclButton = new QPushButton(QApplication::translate("kupaclientslisteditor", "Backup") , this);
	//backupkclButton->show();
	newclientkclButton = new QPushButton(QApplication::translate("kupaclientslisteditor", "New client") , this);
	//newclientkclButton->show();
	sshpairingkclButton = new QPushButton(QApplication::translate("kupaclientslisteditor", "SSH pairing") , this);
	//sshpairingkclButton->show();

	//quitButton = new QPushButton(tr("Quit")); // one left over in the current file as note ( ?! ... )
	//quitButton = new QPushButton(tr("Quit"), this); // one working from a clas file (...)

	// the QActions
	//openAction = new QAction(tr("&Open"), this);
	//saveAction = new QAction(tr("&Save"), this);
	exitAction = new QAction(tr("&Quit"), this);
	exitAction->setShortcuts(QKeySequence::Quit); // Ctrl+Q to quit the app
	savekclAction = new QAction(tr("&Save the Kupa clients list"), this);
	savekclAction->setShortcuts(QKeySequence::Save); // Ctrl+S to save the current clients list
	resetkclAction = new QAction(tr("Reset the K&upa clients list"), this);
	resetkclAction->setShortcuts(QKeySequence::Underline); // Ctrl+U to reset the client list 
	backupkclAction = new QAction(tr("&Backup the Kupa clients list"), this);
	backupkclAction->setShortcuts(QKeySequence::Bold); // Ctrl+B to backup the settings.kupa file
	newclientkclAction = new QAction(tr("&New Kupa client"), this);
	newclientkclAction->setShortcuts(QKeySequence::New); // Ctrl+N to create an empty line in the table
	sshpairingkclAction = new QAction(tr("New SSH &pairing"), this);
	sshpairingkclAction->setShortcuts(QKeySequence::Print); // Ctrl+P to launch the SSH pairing assistant
        
	kupanodesettingsAction = new QAction(tr("&Edit the local Kupa Node settings"), this);
	aboutAction = new QAction(tr("&About Kupa & KCLE"), this);

	// QObject::connect the necessary signals & slots
	// connect actions to signals & slots
	//connect( openAction, SIGNAL( triggered() ), this, SLOT( openSlot()) ); // from 'Notepad'
	//connect( saveAction, SIGNAL( triggered() ), this, SLOT( saveSlot()) ); // from 'Notepad'
	//connect( exitAction, SIGNAL( triggered() ), qApp, SLOT( quit()) ); // qApp quit() ( != than 'Programwin::quitSlot()' ) // WORKING BUT WITHOUT USER CONFIRM
	connect( exitAction, SIGNAL( triggered() ), this, SLOT( quitSlot() ) );
	connect( savekclAction, SIGNAL( triggered() ), this, SLOT( savekclSlot()) );
	connect( resetkclAction, SIGNAL( triggered() ), this, SLOT( resetkclSlot()) );
	connect( backupkclAction, SIGNAL( triggered() ), this, SLOT( backupkclSlot()) );
	connect( newclientkclAction, SIGNAL( triggered() ), this, SLOT( newclientkclSlot()) );
	connect( sshpairingkclAction, SIGNAL( triggered() ), this, SLOT( sshpairingkclSlot()) );

	connect( kupanodesettingsAction, SIGNAL(triggered()), this, SLOT(kupanodesettingsSlot()) );
	connect( aboutAction, SIGNAL(triggered()), this, SLOT(aboutSlot()) );

	// connect buttons to signals & slots
        //connect( quitButton, SIGNAL( clicked() ), this, SLOT( quitSlot() ) ); // the 'quitSlot()' methd asks before quitting ( whereas qApp 'quit()' doesn't ...)
	connect( savekclButton, SIGNAL( clicked() ), this, SLOT( savekclSlot() ) );
	connect( resetkclButton, SIGNAL( clicked() ), this, SLOT( resetkclSlot() ) );
	connect( backupkclButton, SIGNAL( clicked() ), this, SLOT( backupkclSlot() ) );
	connect( newclientkclButton, SIGNAL( clicked() ), this, SLOT( newclientkclSlot() ) );
	connect( sshpairingkclButton, SIGNAL( clicked() ), this, SLOT( sshpairingkclSlot() ) );

	// the menu bar
	fileMenu = menuBar()->addMenu(tr("&Manage Kupa clients list"));
	//fileMenu->addAction(openAction);
	//fileMenu->addAction(saveAction);
	fileMenu->addAction(savekclAction);
	fileMenu->addAction(resetkclAction);
	fileMenu->addAction(backupkclAction);
	fileMenu->addSeparator();
	fileMenu->addAction(newclientkclAction);
	fileMenu->addAction(sshpairingkclAction);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	fileMenu = menuBar()->addMenu(tr("&Manage local Kupa Node"));
        fileMenu->addAction(kupanodesettingsAction);
	fileMenu = menuBar()->addMenu(tr("&About"));
	fileMenu->addAction(aboutAction);

	// setup the layouts & their inner components
	// the follwing is ~ grabage code ( usefull for test-implmenting ! )
	//QVBoxLayout *layout = new QVBoxLayout;
	//layout->addWidget(textEdit);
	//layout->addWidget(quitButton);

	//setLayout(layout);
	//setCentralWidget(textEdit); // to DIGG in the Qt docs ( AS A PERSONNAL GUESS: may be related to not using 'setLayout()'& instead specifying a widget for the entire window ? )
	
	// 'real' layout & components implementation
	// the layouts initialization
	mainLayout = new QVBoxLayout(); // the main layout of the program window
	appheaderLayout = new QHBoxLayout(); // the layout of the app header
	appinfosLayout = new QVBoxLayout(); // the layout holding the App name & the subtitle
	appbuttonsLayout = new QVBoxLayout(); // the layout holding the app header buttons layouts
	appsrbbuttonsLayout = new QHBoxLayout(); // the layout holding the save, reset & backup buttons
	appcsbuttonsLayout = new QHBoxLayout(); // the layout holding the new client & the ssh pairing buttons

	// setup the layouts & components hierarchy
	appinfosLayout->addWidget(appnameLabel);
	appinfosLayout->addWidget(subtitleLabel);
        appinfosLayout->setSpacing(10);
        appinfosLayout->setMargin(10);
        appinfosLayout->setContentsMargins(5, 15, 35, 25); // R syntax: (<margin-left>, <margin-top>, <margin-right>, <margin-bottom>)
	appsrbbuttonsLayout->addWidget(savekclButton);
        appsrbbuttonsLayout->addWidget(backupkclButton);
        appsrbbuttonsLayout->addWidget(resetkclButton);
        appbuttonsLayout->addLayout(appsrbbuttonsLayout);
        appcsbuttonsLayout->addWidget(newclientkclButton);
        appcsbuttonsLayout->addWidget(sshpairingkclButton);
        appbuttonsLayout->addLayout(appcsbuttonsLayout);
	appheaderLayout->addLayout(appinfosLayout);
	appheaderLayout->addLayout(appbuttonsLayout);
	mainLayout->addLayout(appheaderLayout);
	mainLayout->addWidget(kclistView);

	//setLayout(mainLayout); // set the window 'main' layout // seems not be the manner of dealing with a layout with a QMainWindow
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);


	setWindowTitle(tr("KCLE - Kupa clients list editor")); // define the name of the App's window

	// TO IMPLM:
	//  -> check if Kupa settings file is present in the current directory ( & then parse data from it or build random data to finally fill the table with it )
	handleKupaSettingsExistenceAtStartup();
	//  -> center window
	// CURRENTLY IMPLEMENTED IN THE CURRENT FILE AND CALLED FROM THE 'main.cpp' FILE AFTER CALLING 'QMainWindow.show()'
	//  -> code for savekcl / resetkcl / backupkcl / newclientkcl / sshpairingkcl
	
	// test code: adding a QPushButton to the table
	QPushButton *aTableButton = new QPushButton(QApplication::translate("kupaclientslisteditor", "aTableButton"));
        aTableButton->setFocusPolicy(Qt::NoFocus); // we wiil see if it changes stg, bit I guess I should apply that to the cells ...
	kclistView->setIndexWidget(kclistView->model()->index(0, 1), aTableButton);
	connect(aTableButton, SIGNAL(clicked()), this, SLOT(dummySlot())); // yup, nothing gets called when clicking on the button ... except the underlying cell that still receives the 'clicked' event .. ;)
	//connect(aTableButton, SIGNAL(clicked()), this, SLOT(dummySlot));
	// the idea ? keep a button in the table ( as it is more user-friendly than an underlined text for the user to understand he can click on it ) & add a 'row check' to an implemented 'cell click handler'
	//connect( kclistView, SIGNAL(cellClicked(int, int)), this, SLOT(cellClickedSlot(int, int)) ); // connect the newly'implemented 'cellClickedSlot(int row, int col)' fcn to handle the cell single clicks
	connect( kclistView, SIGNAL(clicked(QModelIndex)), this, SLOT(cellClickedSlot(QModelIndex)) ); // same as above
	connect( kclistView, SIGNAL(activated(QModelIndex)), this, SLOT(cellActivatedSlot(QModelIndex)) ); // registers the 'activated' signal to be handled by the 'cellActivated' slot
	// test code: modding a headerItem
	QStandardItem * confiscatedHeader = model.takeHorizontalHeaderItem(2); // try to get the header out of the column ( yup but on, as it replaces the string by the N° of the column ... )
	confiscatedHeader->setForeground(Qt::white);
	//confiscatedHeader->setBackground(QColor("lightblue"));
	confiscatedHeader->setBackground(Qt::white);
	//confiscatedHeader->setFont(QFont("arial", 12));
	model.setHorizontalHeaderItem(2, confiscatedHeader);

	/* what about some CSS ?*/
	//qAapp->setStyleSheet("selection-background-color: red;");
	kclistView->setStyleSheet(//"selection-color: red;"
				  "background: none;"
			          "selection-background-color: blue;"
				  
				  "QTableView { selection-color: green; }"
				  
				  "item { selection-background-color: green; }"
				  "item:focus { selection-background-color: blue; }"
				  "item:active { selection-background-color: blue; }"

                                  " selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5, stop: 0 #FF92BB, stop: 1 white); "

                                  "QStandardItem { "
				  "  selection-color: green; "
				  "  selection-background-color: read; "
				  "}"

			          //" QHeaderView::section:nth-child(3) "
			          //" { "
				  //"   background-color: red; "
				  //" } "

			          //" QHeaderView::section::first "
                                  //" { "
			          //"   background-color: transparent; "
			          //"   color: white; "
		                  //"   padding-left: 4px; "
			          //"   border: 1px solid transparent; "
			          //"  } "

			          "  QHeaderView::section *  "
			          "  { "
		                  "    background-color: red; "
			          "  } ");
}

/* we re-implm the "QMainWindow::resizeEvent" handler fcn*/
void Programwin::resizeEvent(QResizeEvent *event)
{
  QMainWindow::resizeEvent(event);
  qDebug() << "A resize event just happened." << endl;
}

/* we re_implm the "QMainWindow::closeEvent" handler fcn */
void Programwin::closeEvent(QCloseEvent *event)
{
  event->ignore();
  if (QMessageBox::Yes == QMessageBox::question(this, "KCLE: confirm quit", "Are you sure you want to exit KCLE ?", QMessageBox::Yes|QMessageBox::No))
    event->accept();
}

/* ------ the SLOTS ------ */

/* a dummy SLOT for the test implm of buttons in the table view */
void Programwin::dummySlot()
{
  qDebug() << "Hello, slut !" << endl;
  //parentWidget()->cellClickedSlot(const QModelIndex & index);
  //QStandardItem * theParentWidget = parentWidget();
  
  //indexAt ( const QPoint & point )
  QPoint clickPos = kclistView->mapFromGlobal(QCursor::pos()); // should get the mouse position relative to the table view
  qDebug() << "clicked occured at position x: " << clickPos.x() << " " << clickPos.y() << endl;

  // try to see if there's a cell at that position, and if it's the case, trigger its 'cellCLicked()' slot
  //QModelIndex indexPos = kclistView->indexAt(clickPos); // it seems to be an 'invisible glitch' that resides maybe in here -> 'll try to add an 'harcoded adjustement' 'til found why ( ... )
  clickPos.setY( clickPos.y() - 25 ); // hardcoded adjustement
  QModelIndex indexPos = kclistView->indexAt(clickPos);
  if ( indexPos.isValid() ){
    qDebug() << "A cell exists where the button click happened: " << endl;

    // as the index seems valid, we should be able to use the index.row value and get the corresponding line of data in the table
    QString rowCol_nameData = kclistView->model()->data(kclistView->model()->index(indexPos.row(), 0)).toString();
    qDebug() << "Data in clicked row: " << rowCol_nameData << endl;
    // or even call the 'cellClickedSLot()' directly as a test ( ... )
    cellClickedSlot(indexPos); // we call the 'native' cell function on click

  } else {
    qDebug() << "No cell exists in here ..." << endl;
  }
}

/*
void Programwin::dummySlot2(const QModelIndex & index)
{
	  qDebug() << "Hello, slut 2 !" << endl;
}
*/

/* the 'cellClicked()' SLOT */
void Programwin::cellClickedSlot(const QModelIndex & index)
{
  qDebug() << "Cell single clicked: ROW " << index.row() << "COL " << index.column();
  QPoint ckPos = kclistView->mapFromGlobal(QCursor::pos());
  qDebug() << "Cell click position X: " << ckPos.x() << " Y: " << ckPos.y();
  
  // check wich column the cell on wich the single click happened belongs to
  if ( index.column() == 1 )
    qDebug() << "a click just happened on the 'delete buttons' column at row " << index.row() << endl;
  else
    qDebug() << "other column" << endl;
}

/* the 'cellActivated()' SLOT */
void Programwin::cellActivatedSlot(const QModelIndex & index)
{
  qDebug() << "Cell activated is now at ROW " << index.row() << "COL " << index.column();
}


/* the 'open()' SLOT */
void Programwin::openSlot()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
		tr("Text Files (*.txt);;C++ File (*.cpp *.h)"));
	
	if (fileName != ""){
		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly)){
			QMessageBox::critical(this, tr("Error"), tr("Could not open the file"));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
	}
}


/* the 'save()' SLOT */
void Programwin::saveSlot()
{
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                tr("Text Files (*.txt);;C++ File (*.cpp *.h)"));

        if (fileName != ""){
                QFile file(fileName);
                if (!file.open(QIODevice::WriteOnly)){
                        //QMessageBox::critical(this, tr("Error"), tr("Could not save the file"));
                        //return;
                } else {
                	QTextStream stream(&file);
                	stream << textEdit->toPlainText();
			stream.flush();
                	file.close();
		}
        }
}


/* the 'quit()' SLOT */
void Programwin::quitSlot()
{
	/* // following is working code
	QMessageBox messageBox;
	messageBox.setWindowTitle(tr("KCLE: confirm exit action"));
	messageBox.setText(tr("Do you really want to quit ?"));
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	messageBox.setDefaultButton(QMessageBox::No);
	if (messageBox.exec() == QMessageBox::Yes)
	    qApp->quit();
	*/

	// but following is even nicer one-liner ;p
	if (QMessageBox::Yes == QMessageBox::question(this, "KCLE: confirm quit", "Are you sure you want to exit KCLE ?", QMessageBox::Yes|QMessageBox::No))
	  qApp->quit();
}


/* the 'savekcl()' SLOT */
void Programwin::savekclSlot()
{
  // check if a previous settings.kupa fiel is found, if it is so, ask the user if he wishes to overwrite it with the current table view data
                                                                             // if he does -> open the file in write mode & save the data to it
								             // else if he doesn't, abort
						   // if it isn't, open the file in write mode ( I guess that'll auto-create it ) & save the data to it

  // check if a previous settings.kupa file is found
  QFile kupasettingsFile("./settings.kupa"); // path to the settings file is hardcoded to application directory by now
  if (! kupasettingsFile.open(QIODevice::ReadOnly)){ // settings file wasn't found
    
    // open it in write mode & save the data to it
    fillFileWithTableData();
    QMessageBox::information(0, "KCLE: Kupa settings updated.", 
                                "The Kupa settings file now in use can be located in the Kupa directory as 'settings.kupa'"); // alert the user that the settings file was saved successfully
    

  } else { // settings file was found
    
    // ask the user if he wishes to overwrite the existing settngs file with the current table view tada
    QMessageBox messageBox;
    messageBox.setWindowTitle(tr("KCLE: confirm settings overwrite"));
    messageBox.setText(tr("An existing settings.kupa file already exists, do you really want to overwrite its content with the data currently in the table ?"
			  "\n"
			  "Warning: empty rows and partially empty rows will be discarded for the save"));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    int ret = messageBox.exec();
    
    switch (ret){
      case QMessageBox::Yes:
	// Yes was clicked -> overwrite
	fillFileWithTableData();
	QMessageBox::information(0, "KCLE: Kupa settings updated.", 
			            "The Kupa settings file now in use can be located in the Kupa directory as 'settings.kupa'"); // alert the user that the settings file was saved successfully
        break;
      case QMessageBox::No:
	// No was clicked -> abort
	break;
      default:
	// should never be reached
	break;
    }

  }
}
/* the 'resetkcl()' SLOT */
void Programwin::resetkclSlot()
{
  // clear all the data inside the rows of the table view model if the user confirms he wishes to
  //model.clear(); // nope .. as the name implied, it clears the model ( .. removing even the headers previously set )
  
  QMessageBox messageBox;
  messageBox.setWindowTitle(tr("KCLE: confirm clients list reset"));
  messageBox.setText(tr("Are you really sure you wish to delete all the clients present in the current table and reset it to zero ?"));
  messageBox.setStandardButtons(QMessageBox::Reset | QMessageBox::Abort);
  messageBox.setDefaultButton(QMessageBox::Abort);
  int ret = messageBox.exec();

  switch (ret){
    case QMessageBox::Reset:
      // Reset was clicked -> reset table model data
      resetTableData(); // we're not informing the user as it'd be more annoying than useful ( ... )
      break;
    case QMessageBox::Abort:
      // Abort was clicked -> abort
      break;
    default:
      // should never be reached
      break;
  }
  
  // the stuff below was moved to the 'resetTableData' fcn
  //while (model.rowCount() > 0) // remove the rows while there are some left
  //  model.removeRow(0);
  //model.insertRow( model.rowCount() ); // add an empty row ( not to loose the user, nb: we could also clear each of the rows & let them visible, while cleared of their previous content ( ... ) )

}
/* the 'backupkcl()' SLOT */
void Programwin::backupkclSlot()
{
  // make a backup of the settings.kupa file if it is found ( maybe execute a bash command that does a simple 'cp settings.kupa BACKUP_settings.kupa' ? )
                                          // if not found, ask the user if he wishes to make a regular save prior to a backup, as there's nothing to backup for the moment
					                             // if he does, find a way to trigger savekclSlot() ( if not possible, write a simple fcn that 'll call the same code ( ... ) )
  // check if a settings.kupa file is found
  QFile kupasettingsFile("./settings.kupa"); // path to the settings file is hardcoded to application directory by now
  if (! kupasettingsFile.open(QIODevice::ReadOnly)){ // settings file wasn't found
    // shouldn't normally happen UNLESS user deletes the default settings file & do not save one created by himself ... so give him a hint in that cas ;p
    QMessageBox::information(0, "KCLE Error: no Kupa settings found.", 
			        "No Kupa settings file in use were found in the Kupa directory as 'settings.kupa',"
				"try saving your current settings before doing a backup of them."); // alert the user that the settings file was saved successfully
  } else { // settings file was found
    
    // TEST: does closing the first file before opening the second helps ?
    kupasettingsFile.close();
    // check if a previous backup already exists
    QFile kupasettingsbackupFile("./backup_settings.kupa"); // path to the settings file is hardcoded to application directory by now
    if (! kupasettingsbackupFile.open(QIODevice::ReadOnly)){ // settings file backup wasn't found
      backupkSettingsFile(); // backup the Kupa settings file
    } else { // a previous backup already exists
      // ask the user whether to overwrite the already existing settings file backup or to abort the process of creating a backup
      QMessageBox messageBox;
      messageBox.setWindowTitle(tr("KCLE: confirm settings backup overwrite"));
      messageBox.setText(tr("A previous Kupa settings file backup already exists, do you really want to overwrite it with the current settings.kupa file contents ?"));
      messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
      messageBox.setDefaultButton(QMessageBox::No);
      int ret = messageBox.exec();

      switch (ret){
        case QMessageBox::Yes:
          // Yes was clicked -> overwrite
          backupkSettingsFile(); // backup the Kupa settings file
          QMessageBox::information(0, "KCLE: Kupa settings backup done.", 
                                    "The Kupa settings file backup can be located in the Kupa directory as 'backup_settings.kupa'"); // alert the user that the settings file was saved successfully
          break;
        case QMessageBox::No:
          // No was clicked -> abort
          break;
        default:
          // should never be reached
          break;
      }
      
    }
  }
}
/* the 'newClientkcl()' SLOT */
void Programwin::newclientkclSlot()
{
  // add a row in the table view model
  model.insertRow( model.rowCount() );
}
/* the 'sshPairingkcl()' SLOT */
void Programwin::sshpairingkclSlot()
{
  // execute another App from the 'Kupa suite' that may consist in an assistant / dialogs to help the user creating the SSH keys needed for pairing
  KupaSSHPairingWizard * ksshpwizard = new KupaSSHPairingWizard(); // instanciate the wizard ( it creates & holds its page by itself, self contained )
  ksshpwizard->show(); //exec(); // show in a modal way ( user has to accept/reject/close the dialog to be able to return to the app's main window ) ( show -> non-modal | exec -> modal )
}

/* the 'kupanodesettings' SLOT */
void Programwin::kupanodesettingsSlot()
{
  // create an instance of the dialog we want to present to the user to see / edit the current local Kupa Node settings [ ,thus settings file ;p ]
  DialogWindow * dialwin = new DialogWindow();
  dialwin->show(); //exec();  // show in a modal way ( user has to accept/reject/close the dialog to be able to return to the app's main window ) ( show -> non-modal | exec -> modal )
}

/* the 'about' SLOT */
void Programwin::aboutSlot()
{
  // create an instance of a QWebView ( QWebElement ? ) that talks a little bit about Kupa ... and 2 words about me ;)
  
}

// ------ static fucntions ( non-SLOTS ) //

/* fcn that checks the presence of a Kupa settings file ('settings.kupa') in the current directory ( the one this application is executed from ) */
void Programwin::handleKupaSettingsExistenceAtStartup()
{
  QFile kupasettingsFile("./settings.kupa"); // path to the settings file is hardcoded to application directory by now
  if (! kupasettingsFile.open(QIODevice::ReadOnly)){ // settings file wasn't found
    
    QMessageBox::information(0, "Error: No Kupa settings file found.", kupasettingsFile.errorString()); // alert the user if no config file has been found

    rows << (QStringList() << "StephaneAG_macbookpro" << "stephaneadamgarnier" << "192.168.1.7" << "22" << "/Applications/Kupa")
	 << (QStringList() << "StephaneAG_zenbook" << "stephaneag" << "192.168.1.18" << "22" << "/home/stephaneag/Kupa/");

    fillTableModelWithRows(rows); // use the fcn declared right below to fill up the table model with the just-created rows

    kclistView->resizeColumnsToContents(); // force a resize of the columns while keeping them interactive
  
  } else { // settings file was found
    
    QTextStream kupasettingsIn(&kupasettingsFile); // create a text stream pointing to the kupa settigns file wich has been checked present ( above )
    while (! kupasettingsIn.atEnd()){ // fetch data from the file until we reach the end of it
      QString kupasettingsLine = kupasettingsIn.readLine();
      rows << (QStringList() << kupasettingsLine.split(" ")); // split the line as a QStringList & append it to the 'QList<QStringList> rows' declared above
    }
    kupasettingsFile.close(); // close the file

    fillTableModelWithRows(rows); // use the fcn declared right below to fill up the table model with the just-created rows

    kclistView->resizeColumnsToContents(); // force a resize of the columns while keeping them interactive
  
  }
}

/* fcn that does a backup of the settings.kupa file */
void Programwin::backupkSettingsFile()
{
  qDebug() << "Hello backup !";
}

/* fcn that resets the table data */
void Programwin::resetTableData()
{
  while (model.rowCount() > 0) // remove the rows while there are some left
    model.removeRow(0);
  model.insertRow( model.rowCount() ); // add an empty row ( not to loose the user, nb: we could also clear each of the rows & let them visible, while cleared of their previous content ( ... ) )
}

/* fcn that fills the table model from the rows (a 'QList<QStringList>') passed as parameter */
void Programwin::fillTableModelWithRows(QList<QStringList> rows)
{
  foreach( QStringList row, rows ){
    QList<QStandardItem *> items;
    foreach( QString text, row ){
      //items.append( new QStandardItem(text) );
      QStandardItem * stdItem = new QStandardItem(text);
      //stdItem->setFocusPolicy(Qt::NoFocus); // we wiil see if it changes stg, bit I guess I should apply that to the cells ...
      //stdItem->setFlags(0); // disable item to prevent focus // note what I'm looking after
      items.append(stdItem);
    }
    model.appendRow(items);
  }
}

/* fcn that open a file using the provided filename in WriteOnly mode & write the content of the table to it */
void Programwin::fillFileWithTableData()
{
  // open the file corresponding to the name passed as parameter in WriteOnly mode
  //fillFileWithTableData(QFile file)
  QFile kupasettingsFile("./settings.kupa"); // path to the settings file is hardcoded to application directory by now
  if ( ! kupasettingsFile.open(QIODevice::WriteOnly)){ // couldn't open file in WriteOnly mode
	  QMessageBox::information(0, "error", kupasettingsFile.errorString()); // alert user of the error while opening
  } else { // fopening file for writing succeeded

  // get the data from the table & 'format it' to the Kupa settings file format ( ... )
  QString tableDataStr; // create a QString that 'll hold the data from the table model, line by line
  QTextStream fileOut(&kupasettingsFile); // create a QTextStream that 'll be used to write the data from the table to the file using the QString

  // [ TO ADD: check if rows other than the last one in the table are empty -> remove them from the table OR change index of the content below it ]
  // [ TO ADD: check if the last row in the table is empty -> remove it ]
  // [ TO ADD: check if the table stills contains stuff to write to the settings file after the above checks/actions ]
  // [ TO ADD: If so ( overall ), do the following || else, inform the user that there is nothing to save ( ... ) ]
  
  // look for empty rows & delete them if some are found
  for (int row = 0; row < model.rowCount(); row++){ // loop over all the rows present in the table model

    // check if current row is empty or not
    if ( ( !model.item(row, 0) || model.item(row, 0)->text().isEmpty() )
      && ( !model.item(row, 1) || model.item(row, 1)->text().isEmpty() )
      && ( !model.item(row, 2) || model.item(row, 2)->text().isEmpty() )
      && ( !model.item(row, 3) || model.item(row, 3)->text().isEmpty() )
      && ( !model.item(row, 4) || model.item(row, 4)->text().isEmpty() ) ){

      qDebug() << "row is fully empty: discarding the row";
      //model.removeRow(row); //model.removeRows(row, 1); // actually delete the empty row
      // TO DO: "A cell with missing informations was be discarded during the save"
    }
  //}
  
  // actually write the the data existing in the table to the settings file or ask user what to do with missing data
  //for (int row = 0; row < model.rowCount(); row++){ // loop over all the rows present in the table model
    
    else if ( !model.item(row, 0) || model.item(row, 0)->text().isEmpty() ){ // check if the current row's NAME cell is empty

      qDebug() << "row has the NAME missing"; // as row is lacking the name, propose the user to set it or to remove the entire row ?

    } else if ( !model.item(row, 1) || model.item(row, 1)->text().isEmpty() ){ // check if the current row's LOGIN cell is empty
      
      qDebug() << "row has the LOGIN  missing";
    
    } else if ( !model.item(row, 2) || model.item(row, 2)->text().isEmpty() ){ // check if the current row's IP cell is empty
      
      qDebug() << "row has the IP  missing";

    } else if ( !model.item(row, 3) || model.item(row, 3)->text().isEmpty() ){ // check if the current row's PORT cell is empty
    
      qDebug() << "row has the PORT  missing";

    } else if ( !model.item(row, 4) || model.item(row, 4)->text().isEmpty() ){ // check if the current row's PATH cell is empty

      qDebug() << "row has the PATH  missing";
    
    } else { // current row is fully filled with settings: we can add it to the saved settings file

      tableDataStr = model.item(row, 0)->text() + " " 
                   + model.item(row, 1)->text() + " "
                   + model.item(row, 2)->text() + " "
                   + model.item(row, 3)->text() + " "
                   + model.item(row, 4)->text();
      fileOut << tableDataStr << endl;

    }
  }

  kupasettingsFile.close(); // optionnal close as the QFile destructor 'll already do it

  // inform the user that all went well ( ... )
  }

}

/* fcn the centers the App window on the current screen ( AFTER it has been made visible ! ) */
void Programwin::centerOnScreen()
{
  // get the current window's dimensions
  QSize currentwindowSize = size();
  int currentwindowwidth = currentwindowSize.width();
  int currentwindowheight = currentwindowSize.height();
  qDebug() << "Computed window dimensions : " << currentwindowwidth << "x" << currentwindowheight;

  // get the current screen's dimensions
  QSize screenavailableSize = QApplication::desktop()->availableGeometry().size();
  int screenavailablewidth = screenavailableSize.width();
  int screenavailableheight = screenavailableSize.height();
  qDebug() << "Current screen dimensions: " << screenavailablewidth << "x" << screenavailableheight;

  // actually position it in the center of the screen
  setGeometry( QStyle::alignedRect( Qt::LeftToRight, Qt::AlignCenter, currentwindowSize, QApplication::desktop()->availableGeometry() ) );
}
