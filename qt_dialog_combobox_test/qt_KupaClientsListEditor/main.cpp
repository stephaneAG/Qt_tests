/*
 *  Kupa clients list editor - Qt version
 *
 *  This little application has been written to ease the process of modifying the clients
 *  to wich the Kupa shared klipboard is shared with.
 *
 *  Note: SSH keys must be setup correctly for all the clients for Kupa to work ,as usual.
 *
 *
 *  by StephaneAG 2013
 *
*/
 

/*
 *  WIP IMPLM
 *
 *  code will be separated in different files in the next versions
 *  the current file in narly a test implm of the different GUi elements, and is especially lacking the parsing part (...)
*/


#include <QtGui>

/* wip-implm fcns*/

/* fcn that simpley displays 'Hello' on the console stdout */

void printHelloOnConsole()
{
  qDebug() << "Hello";
}

/* Main App code */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window; // simple window populated in the current file by now

    // elements that will populate the window
      // the Application name 
      QLabel *appnameLabel = new QLabel( QApplication::translate("kupaclientslisteditor", "Welcome to the Kupa clients list editor") );
      // the subtitle ( the spaces at the end are just a littl' hack for a littl' more space ;p )
      QLabel *subtitleLabel = new QLabel( QApplication::translate("kupaclientslisteditor", "Use this app to easily specify the people you wish to add to your shared clipboard."
			      "\n"
			      "Note that you still need to setup the SSH keys needed for securely pairing devices") );
      //  the 'save' button
      QPushButton *savekclButton = new QPushButton( QApplication::translate("kupaclientslisteditor", "Save") , &window);
      //savekclButton->move(200, 20);
      savekclButton->show();
      //  the 'reset' button
      QPushButton *resetkclButton = new QPushButton( QApplication::translate("kupaclientslisteditor", "Reset") , &window);
      //resetkclButton->move(200, 20);
      resetkclButton->show();
      // the 'backup' button
      QPushButton *backupkclButton = new QPushButton( QApplication::translate("kupaclientslisteditor", "Backup") , &window);
      //backupkclButton->move(200, 20);
      backupkclButton->show();
      // the 'new client' button
      QPushButton *newclientkclButton = new QPushButton( QApplication::translate("kupaclientslisteditor", "New client") , &window);
      //newclientkclButton->move(200, 20);
      newclientkclButton->show();
      // the 'SSH pairing' button
      QPushButton *sshpairingkclButton = new QPushButton( QApplication::translate("kupaclientslisteditor", "SSH pairing") , &window); 
      //sshpairingkclButton->move(200, 20);
      sshpairingkclButton->show();
      // the table view
      QTableView *kclistView = new QTableView();

    // layouts that will hold the previously defined elements
      // the main layout
      QVBoxLayout *mainLayout = new QVBoxLayout();
      // the layout holding the app name, the subtitle & the new/open/save/save as buttons
      QHBoxLayout *appheaderLayout = new QHBoxLayout();
        // the layout that will hold the App name and the subtitle
	QVBoxLayout *appinfosLayout = new QVBoxLayout();
	// tha layout that will hold the buttons
	QVBoxLayout *appbuttonsLayout = new QVBoxLayout();
	 // the layout that will hold the save, reset & backup buttons
	 QHBoxLayout *appsrbbuttonsLayout = new QHBoxLayout();
	 // the layout that will hold the new client & the ssh pairing buttons
	 QHBoxLayout *appcsbuttonsLayout = new QHBoxLayout();
      
    // setup of the layouts and their inner elements
      // the 'appheader' layout children
      //appheaderLayout->addWidget(appnameLabel); // v0.1
      //appheaderLayout->addWidget(subtitleLabel); // v0.1
      appinfosLayout->addWidget(appnameLabel);
      appinfosLayout->addWidget(subtitleLabel);
       // little more customisation of the appinfosLayout
       appinfosLayout->setSpacing(10);
       appinfosLayout->setMargin(10);
       appinfosLayout->setContentsMargins(5, 15, 35, 25); // R syntax: (<margin-left>, <margin-top>, <margin-right>, <margin-bottom>)
      //appbuttonsLayout->addWidget(newkclButton);
      //appbuttonsLayout->addWidget(openkclButton);
      //appbuttonsLayout->addWidget(savekclButton);
      appsrbbuttonsLayout->addWidget(savekclButton);
      appsrbbuttonsLayout->addWidget(backupkclButton);
      appsrbbuttonsLayout->addWidget(resetkclButton);
      appbuttonsLayout->addLayout(appsrbbuttonsLayout);
      appcsbuttonsLayout->addWidget(newclientkclButton);
      appcsbuttonsLayout->addWidget(sshpairingkclButton);
      appbuttonsLayout->addLayout(appcsbuttonsLayout);
      appheaderLayout->addLayout(appinfosLayout);
      appheaderLayout->addLayout(appbuttonsLayout);
      // the main layout
      mainLayout->addLayout(appheaderLayout); // here, we add the 'appheader' layout as a nested layout
      mainLayout->addWidget(kclistView);

      window.setLayout(mainLayout);

    // setup of the model that will be used by the view & configuration of the view
    // R: in the 'settings.kupa' file -> StephaneAG_macbookpro stephaneadamgarnier 192.168.1.7 22 /Applications/Kupa
    //                                   StephaneAG_zenbook 192.168.1.18 22 ~/home/stephaneag/Kupa/Kupa.node
    //                            aka -> <client_name> <client_login> <client_ip_address> <client_connection_port> <client_path_to_kupa_directory>
      QStandardItemModel model;
      model.setHorizontalHeaderLabels(
        QStringList() << QApplication::translate("kupaclientslisteditor", "Name")
		      << QApplication::translate("kupaclientslisteditor", "Login")
                      << QApplication::translate("kupaclientslisteditor", "IP adress")
                      << QApplication::translate("kupaclientslisteditor", "Port")
                      << QApplication::translate("kupaclientslisteditor", "Kupa remote path")
      );
    
    // check if a 'settings.kupa' file exists in the current directory, & fill up the table with the data found in it if it's found, else create dummy data & fill the table with that (...)
    QFile kupasettingsFile("./settings.kupa"); // path to the settings file is hardcoded to application directory by now
    if (! kupasettingsFile.open(QIODevice::ReadOnly)){ // settings file wasn't found
      QMessageBox::information(0, "error", kupasettingsFile.errorString()); // alert the user if no config file has been found
    //} // creating & using dummy stuff as data to fill the table ( following code )

    // create some data to fill the table  
//      QList<QStringList> rows = QList<QStringList>()
//        << (QStringList() << "StephaneAG_macbookpro" << "stephaneadamgarnier" << "192.168.1.7" << "22" << "/Applications/Kupa")
//	<< (QStringList() << "StephaneAG_zenbook" << "stephaneag" << "192.168.1.18" << "22" << "/home/stephaneag/Kupa/");
        QList<QStringList> rows = QList<QStringList>();
	        rows << (QStringList() << "StephaneAG_macbookpro" << "stephaneadamgarnier" << "192.168.1.7" << "22" << "/Applications/Kupa")
		     << (QStringList() << "StephaneAG_zenbook" << "stephaneag" << "192.168.1.18" << "22" << "/home/stephaneag/Kupa/");

    // fill the model with the data set as the rows ( just above )
      foreach( QStringList row, rows ){
        QList<QStandardItem *> items;
	foreach( QString text, row )
	  items.append( new QStandardItem(text) );
	model.appendRow(items);
      }

    } else { // settings file was found
      //QTextStream kupasettingsIn(&kupasettingsFile);
      //while (! kupasettingsIn.atEnd()){
        //QString line = kupasettingsIn.readLine();
	//QStringList fields = line.split(" ");
	//model.appendRow(fields);
      //}
      //kupasettingsFile.close();
      
      // 'Tef way !'
      QList<QStringList> rows = QList<QStringList>(); // don't directly populate it this time ( referring to the dummy data above )
      
      QTextStream kupasettingsIn(&kupasettingsFile); // create a text stream pointing to the kupa settigns file wich has been checked present ( above )
      while (! kupasettingsIn.atEnd()){ // fetch data from the file until we reach the end of it
        QString kupasettingsLine = kupasettingsIn.readLine();
	rows << (QStringList() << kupasettingsLine.split(" ")); // split the line as a QStringList & append it to the 'QList<QStringList> rows' declared above
      }
      kupasettingsFile.close(); // close the file

    // fill the model with the data set as the rows ( just above: REAL data this time )
      foreach( QStringList row, rows ){
        QList<QStandardItem *> items;
        foreach( QString text, row )
          items.append( new QStandardItem(text) );
        model.appendRow(items);
      }

    }

    // setup the view
      kclistView->setModel(&model);
      kclistView->verticalHeader()->hide(); // hide the table vetical headers ( index numbers )
      //model.setRowCount(10); // specify an arbitrary number of visible rows ( normally, the n° of rows corresponds to the n° of elements in the 'QList<QStringList> row' )
      model.insertRow( model.rowCount() ); // add a new row at the end of the existing ones
      //kclistView->setShowGrid(false); // specify to show or hide the grid of the table
      kclistView->setStyleSheet("QTableView{selection-background-color: red;}"); // specify the background color of the selected cell
      kclistView->horizontalHeader()->setStretchLastSection(true); // actually to remember but not what I am looking for
      kclistView->horizontalHeader()->setResizeMode(QHeaderView::Interactive); // allows the columns to be resized manually by the user
      //kclistView->horizontalHeader()->setResizeMode(QHeaderView::Stretch); // allows the columns to stretch evenly
      //kclistView->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents); // note: needs 'setStretchLastSection(true)' ( commented out above ) to fill the entire available space
      
      // littl' hack to force a resize of the columns while keeping them interactive ( resizable by the user ) ( with a toggle to re-do it on windowResize event ? (...) )
      //kclistView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents); // seems that 'd be ok with a lastSectStretch
      kclistView->resizeColumnsToContents(); // same effect as above, but maybe less 'hackish'
      // other few adjustements that may surely benefit some googl'-diggin'
      kclistView->horizontalHeader()->setClickable(false);

    // quickly setup some basic window settings & show it
    window.setWindowTitle( QApplication::translate("kupaclientslisteditor", "Kupa clients list editor") );
    
    window.show(); // CAREFUL! : execute the code below ONLY AFTER calling 'show()' on an instance of QWindow || QMainWindow ( else the computed dimensions seems to stick to 640x480 )
    
    // center the window on the screen ( AFTER it has been made visible ! )
    // get the current window's dimensions
    QSize currentwindowSize = window.size();
    int currentwindowwidth = currentwindowSize.width();
    int currentwindowheight = currentwindowSize.height();
    qDebug() << "Computed window dimensions : " << currentwindowwidth << "x" << currentwindowheight;

    // get the current screen's dimensions
    QSize screenavailableSize = app.desktop()->availableGeometry().size();
    int screenavailablewidth = screenavailableSize.width();
    int screenavailableheight = screenavailableSize.height();
    qDebug() << "Current screen dimensions: " << screenavailablewidth << "x" << screenavailableheight;
    
    // actually position it in the center of the screen
    window.setGeometry( QStyle::alignedRect( Qt::LeftToRight, Qt::AlignCenter, currentwindowSize, app.desktop()->availableGeometry() ) );

    printHelloOnConsole(); // test the wip(imlpm fcn


    return app.exec();
}
